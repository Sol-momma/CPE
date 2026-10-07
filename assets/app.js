/* CPE Study — 49問と26選集を1ページで読む学習アプリ（ビルド不要・静的ファイルのみ）
 * 画面: 表紙(#/)・問題(#/<set>/problems/<id>)・PDF一覧(#/<set>/pdf)・型(#/<set>/patterns)
 * データ: data/types.js, data/cpe49.js, data/cpe26.js（切り替え時に読み込む）
 */
(() => {
'use strict';

const SETS = [
  { id: '49', en: 'CPE 49', ja: 'CPE 49問', zh: 'CPE 49題', n: 49 },
  { id: '26', en: 'CPE26 Selection', ja: 'CPE26選集', zh: 'CPE26選集', n: 56 },
];
const LEVELS = {
  1: { en: 'Easy', ja: 'やさしい', zh: '簡單', short: 'Easy' },
  2: { en: 'Easy', ja: 'やさしい', zh: '簡單', short: 'Easy' },
  3: { en: 'Medium', ja: 'ふつう', zh: '中等', short: 'Med.' },
  4: { en: 'Hard', ja: 'むずかしい', zh: '困難', short: 'Hard' },
};
const TIERS = [
  { lv: '★', en: 'First steps', ja: 'はじめの一歩', zh: '入門', why: '入力を読んで、式1本かループ1つで答えが出る。' },
  { lv: '★★', en: 'Loops & arrays', ja: 'ループと配列', zh: '迴圈與陣列', why: '% 10、配列で数える、sort など、型を1つ使えば解ける。' },
  { lv: '★★★', en: 'Combining patterns', ja: '型を組み合わせる', zh: '組合模式', why: '型を2つ組み合わせる。または出力の形にひと工夫いる。' },
  { lv: '★★★★', en: 'Tricky ones', ja: '落とし穴が多い', zh: '陷阱較多', why: '公式を自分で作る、小数の誤差、ルールが細かい、のどれかがある。' },
];
const LOOP_EX = {
  '49': { eof: [2, 15, 24], zero: [5, 10, 35], t: [1, 19, 20], line: [7, 8, 12, 43] },
  '26': { eof: [101, 111, 121], zero: [41, 42, 51], t: [12, 43, 113], line: [24, 133, 143] },
};
const exId = (set, n) => (set === '49' ? `CPE49-${String(n).padStart(2, '0')}` : `CPE26-${String(n).padStart(3, '0')}`);
const TYPES = window.CPE_TYPES || {};

/* ───────── 小さな道具 ───────── */
const $ = (sel, root = document) => root.querySelector(sel);
const $$ = (sel, root = document) => [...root.querySelectorAll(sel)];
const esc = (s) => String(s).replace(/[&<>"']/g, (c) => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;' }[c]));
const t3 = (en, ja, zh, cls = '') => `<span class="t3 ${cls}"><span class="en">${esc(en)}</span><span class="ja">${esc(ja)}</span><span class="zh">${esc(zh)}</span></span>`;
const t3o = (o, cls = '') => t3(o.en, o.ja, o.zh, cls);
const store = {
  get(k, d) { try { const v = localStorage.getItem(k); return v == null ? d : JSON.parse(v); } catch { return d; } },
  set(k, v) { try { localStorage.setItem(k, JSON.stringify(v)); } catch { /* 保存できない環境でも動く */ } },
};
const ICONS = {
  list: '<path d="M8 6h12M8 12h12M8 18h12M3.5 6h.01M3.5 12h.01M3.5 18h.01"/>',
  prev: '<path d="M15 5l-7 7 7 7"/>', next: '<path d="M9 5l7 7-7 7"/>',
  shuffle: '<path d="M3 7h3.5c5 0 5 10 10 10H21M3 17h3.5c1.6 0 2.8-.7 3.8-1.8M13.7 8.8C14.7 7.7 15.5 7 17 7h4M18 4l3 3-3 3M18 14l3 3-3 3"/>',
  check: '<path d="M5 12.5l4.5 4.5L19 7.5"/>',
  ext: '<path d="M14 4h6v6M20 4l-9 9M18 14v5a1 1 0 01-1 1H5a1 1 0 01-1-1V7a1 1 0 011-1h5"/>',
  sun: '<circle cx="12" cy="12" r="4"/><path d="M12 3v2M12 19v2M3 12h2M19 12h2M5.6 5.6l1.4 1.4M17 17l1.4 1.4M5.6 18.4L7 17M17 7l1.4-1.4"/>',
  moon: '<path d="M20 14.5A8 8 0 019.5 4 8 8 0 1020 14.5z"/>',
  menu: '<path d="M4 7h16M4 12h16M4 17h16"/>',
  search: '<circle cx="11" cy="11" r="6.5"/><path d="M20 20l-4.2-4.2"/>',
  filter: '<path d="M4 6h16M7 12h10M10 18h4"/>',
  copy: '<rect x="9" y="9" width="11" height="11" rx="2"/><path d="M5 15V6a2 2 0 012-2h9"/>',
  code: '<path d="M8 8l-4 4 4 4M16 8l4 4-4 4M13.5 5l-3 14"/>',
  x: '<path d="M6 6l12 12M18 6L6 18"/>',
  home: '<path d="M4 11l8-7 8 7M6 10v9h12v-9"/>',
  palette: '<path d="M12 3a9 9 0 100 18c1.4 0 2-.8 2-1.7 0-1-.9-1.4-.9-2.4 0-1 .8-1.7 1.9-1.7H17a4 4 0 004-4c0-4.4-4-8.2-9-8.2z"/><path d="M7.5 11.5h.01M10 7.8h.01M14.5 7.8h.01"/>',
};
const SKINS = [
  { id: 'sumi', en: 'Sumi-e', ja: '水墨', zh: '水墨' },
  { id: 'a', en: 'Vogue', ja: '雑誌（Google × Vogue）', zh: '時尚雜誌' },
  { id: 'b', en: 'Pop dots', ja: '1950年のドット', zh: '1950 網點' },
  { id: 'c', en: '8-bit', ja: 'ファミコン風', zh: '紅白機風' },
];
const ic = (n) => `<svg class="ic" viewBox="0 0 24 24" aria-hidden="true">${ICONS[n]}</svg>`;

/* ───────── 状態 ───────── */
const S = {
  view: 'home', set: store.get('cpe:view', { set: '49' }).set || '49', id: null,
  q: '', type: null, tier: 0, unsolved: false, order: 'cat',
  ltab: 'desc', lang: 'en', rtab: 'sample', mpane: 'problem', filterOpen: false, drawer: false, pop: null, reopen: false, focusSearch: false,
};
let solved = store.get('cpe:solved', {});
const layout = Object.assign({ split: 46, hsplit: 66 }, store.get('cpe:layout', {}));
const data = {};
const pending = {};
const D_ = () => data[S.set];

function ensureSet(id) {
  if (data[id]) return Promise.resolve(data[id]);
  if (pending[id]) return pending[id];
  pending[id] = new Promise((resolve, reject) => {
    const s = document.createElement('script');
    s.src = `data/cpe${id}.js?v=20261007h`;
    s.onload = () => { data[id] = window.CPE_SETS[id]; resolve(data[id]); };
    s.onerror = () => { delete pending[id]; reject(new Error(`failed to load ${s.src}`)); };
    document.head.append(s);
  });
  return pending[id];
}

/* ───────── ルーティング ───────── */
const hrefOf = (set, view, id) => (view === 'home' ? '#/' : `#/${set}/${view}${id ? '/' + encodeURIComponent(id) : ''}`);
function parseHash() {
  const m = location.hash.match(/^#\/(49|26)\/(problems|pdf|patterns)(?:\/([^/]+))?$/);
  if (m) return { set: m[1], view: m[2], id: m[3] ? decodeURIComponent(m[3]) : null };
  return { set: S.set, view: 'home', id: null };
}
function go(set, view, id) {
  const h = hrefOf(set, view, id);
  if (location.hash === h || (h === '#/' && (location.hash === '' || location.hash === '#'))) applyRoute(); else location.hash = h;
}
async function applyRoute() {
  const r = parseHash();
  const setChanged = r.set !== S.set;
  S.set = r.set; S.view = r.view;
  if (setChanged) { S.q = ''; S.type = null; S.tier = 0; S.unsolved = false; S.order = 'cat'; }
  store.set('cpe:view', { set: S.set });
  closeLayer();
  try {
    await ensureSet(S.set);
    if (S.view === 'home') await ensureSet(SETS.find((s) => s.id !== S.set).id);
  } catch (e) {
    $('#app').innerHTML = '<p class="boot">Failed to load data. Reload the page. / データを読み込めませんでした。再読み込みしてください。</p>';
    return;
  }
  const D = D_();
  if (S.view === 'problems') {
    if (r.id && D.items.some((i) => i.id === r.id)) S.id = r.id;
    else {
      const last = store.get('cpe:last:' + S.set, null);
      S.id = D.items.some((i) => i.id === last) ? last : nextUp(D).id;
      history.replaceState(null, '', hrefOf(S.set, 'problems', S.id));
    }
    store.set('cpe:last:' + S.set, S.id);
  }
  render();
  window.scrollTo({ top: 0 });
  if (S.reopen) { S.reopen = false; openDrawer(); }
  (window.requestIdleCallback || ((f) => setTimeout(f, 1500)))(() => SETS.forEach((s) => ensureSet(s.id).catch(() => {})));
}
const nextUp = (D) => D.items.slice().sort((a, b) => a.rank - b.rank).find((x) => !solved[x.id]) || D.items[0];

/* ───────── 絞り込み・並び ───────── */
function matches(it, f) {
  if (f.q) {
    const hay = `${it.id} ${it.no} ${it.title} uva${it.uva} ${it.uva}`.toLowerCase();
    if (!f.q.toLowerCase().split(/\s+/).every((w) => hay.includes(w))) return false;
  }
  if (f.type && !it.types.includes(f.type)) return false;
  if (f.tier && it.tier !== f.tier) return false;
  if (f.unsolved && solved[it.id]) return false;
  return true;
}
function groups(filter = S) {
  const D = D_();
  const vis = D.items.filter((x) => matches(x, filter));
  if (S.order === 'rank') return [{ key: 'rank', head: null, items: vis.sort((a, b) => a.rank - b.rank) }];
  if (S.order === 'no') return [{ key: 'no', head: null, items: vis.sort((a, b) => a.no.localeCompare(b.no)) }];
  return D.cats.map((c) => ({ key: c.id, head: t3o(c, 'c'), items: vis.filter((x) => x.cat === c.id).sort((a, b) => a.no.localeCompare(b.no)) })).filter((g) => g.items.length);
}
const flat = (gs) => gs.flatMap((g) => g.items);
const solvedCount = (setId) => Object.keys(solved).filter((k) => solved[k] && k.startsWith(`CPE${setId}-`)).length;
const setMeta = (id) => SETS.find((s) => s.id === id);
const lvChip = (it) => `<span class="chip lvl" data-l="${it.tier}" title="${esc(LEVELS[it.tier].zh)}">${t3(LEVELS[it.tier].en, LEVELS[it.tier].ja, LEVELS[it.tier].zh, 'c')}</span>`;
const typeChips = (it) => it.types.map((k) => `<span class="chip">${t3o(TYPES[k].name, 'c')}</span>`).join('');

/* ───────── テーマ ───────── */
const effectiveDark = () => { const t = document.documentElement.dataset.theme; return t === 'ink' || (t === 'auto' && matchMedia('(prefers-color-scheme: dark)').matches); };
function toggleTheme() {
  const next = effectiveDark() ? 'paper' : 'ink';
  document.documentElement.dataset.theme = next; store.set('cpe:theme', next);
  $$('[data-act="theme"]').forEach((b) => { b.innerHTML = ic(effectiveDark() ? 'sun' : 'moon'); });
}
const skinBtn = () => `<button type="button" class="btn icon" data-act="skin" aria-label="Style / 見た目 / 風格" title="Style / 見た目 / 風格" aria-haspopup="menu">${ic('palette')}</button>`;
function setSkin(id) {
  if (id === 'sumi') delete document.documentElement.dataset.skin; else document.documentElement.dataset.skin = id;
  store.set('cpe:skin', id);
  closeLayer(); render();
}
function openSkinMenu(btn) {
  const r = btn.getBoundingClientRect(), cur = Ink.skin();
  S.pop = 'skin';
  $('#layer').innerHTML = `<div class="scrim" data-act="close" style="background:transparent"></div><div class="pop" role="menu" style="top:${r.bottom + 6}px;right:${Math.max(8, innerWidth - r.right)}px">
    ${SKINS.map((k) => `<button type="button" role="menuitemradio" aria-checked="${k.id === cur}" data-act="setskin" data-s="${k.id}"><span style="width:18px">${k.id === cur ? ic('check') : ''}</span>${t3(k.en, k.ja, k.zh, 'c')}</button>`).join('')}</div>`;
}
const themeBtn = () => `<button type="button" class="btn icon" data-act="theme" aria-label="Theme / テーマ / 主題" title="Theme / テーマ / 主題">${ic(effectiveDark() ? 'sun' : 'moon')}</button>`;

/* ───────── 描画の振り分け ───────── */
function render() {
  const app = $('#app');
  if (S.view === 'problems') renderWorkspace(app);
  else if (S.view === 'home') renderHome(app);
  else renderPage(app);
  const it = S.view === 'problems' ? currentItem() : null;
  document.title = it ? `${it.no}. ${it.title} · CPE Study` : 'CPE Study · CPE 学習 · CPE 學習';
}

/* ───────── 紙面の共通部分（題字） ───────── */
function mast(current) {
  const d = new Date();
  const en = d.toLocaleDateString('en-US', { weekday: 'long', year: 'numeric', month: 'long', day: 'numeric' });
  const ja = d.toLocaleDateString('ja-JP', { year: 'numeric', month: 'long', day: 'numeric', weekday: 'short' });
  const nav = (href, label, key) => `<a href="${href}"${current === key ? ' aria-current="page"' : ''}>${label}</a>`;
  return `<header class="mast">
    <div class="mast-top">
      <div class="mast-date">${esc(en)}<br>${esc(ja)}</div>
      <a class="word" href="#/" aria-label="CPE Study — Home">${Ink.mark()}<b>CPE Study</b></a>
      <div class="mast-tools"><button type="button" class="btn" data-act="list">${ic('list')}<span class="t3 c"><span class="en">Problem List</span><span class="ja">問題一覧</span></span></button>${skinBtn()}${themeBtn()}</div>
    </div>
    <hr class="mast-rule">
    <nav class="mast-nav" aria-label="Sections / 目次">
      ${nav('#/', t3('Front page', '表紙', '首頁', 'c'), 'home')}
      ${nav('#/49/problems', t3('CPE 49', 'CPE 49問', 'CPE 49題', 'c'), 'set49')}
      ${nav('#/26/problems', t3('CPE26 Selection', 'CPE26選集', 'CPE26選集', 'c'), 'set26')}
      ${nav(hrefOf(S.set, 'patterns'), t3('Patterns', '考え方の型', '解題模式', 'c'), 'patterns')}
      ${nav(hrefOf(S.set, 'pdf'), t3('PDFs', 'PDF一覧', 'PDF 列表', 'c'), 'pdf')}
    </nav>
  </header>`;
}

/* ───────── 表紙 ───────── */
function renderHome(app) {
  const D = data[S.set];
  const it = nextUp(D);
  const resume = (() => { for (const s of [S.set, ...SETS.map((x) => x.id)]) { const id = store.get('cpe:last:' + s, null); if (id && data[s]) { const f = data[s].items.find((x) => x.id === id); if (f) return { set: s, it: f }; } } return null; })();
  const setCol = (s) => {
    const DD = data[s.id]; if (!DD) return '';
    const done = solvedCount(s.id), pct = Math.round((done / s.n) * 100);
    return `<section class="col"><h2>${t3(s.en, s.ja, s.zh)}</h2>
      <div class="sethead">${Ink.meter(pct, 'lg', done, s.n, `${done} / ${s.n}`, true)}<div class="shn"><div class="big">${done}<span style="font-size:1.1rem;color:var(--muted)"> / ${s.n}</span></div><div class="small">${t3('solved', '解いた', '已解', 'c')}</div></div></div>
      <ul class="catlist">${DD.cats.map((c) => { const items = DD.items.filter((x) => x.cat === c.id); return `<li><a href="${hrefOf(s.id, 'problems', items[0].id)}"><span>${t3o(c, 'c')}</span><span class="n">${items.filter((x) => solved[x.id]).length}/${items.length}</span></a></li>`; }).join('')}</ul></section>`;
  };
  app.innerHTML = `<div class="paper">${mast('home')}
    <section class="lead">
      <div class="lead-text">
        <p class="lead-kick">${t3('Up next in ' + setMeta(S.set).en, '次の一問', '下一題', 'c')}</p>
        <h1>${esc(it.title)}</h1>
        <p class="dek" lang="ja">${esc(it.idea)}</p>
        <div class="chips">${lvChip(it)}<span class="chip">UVa ${it.uva}</span>${typeChips(it)}</div>
        <div class="cta"><a class="btn solid" href="${hrefOf(S.set, 'problems', it.id)}">${t3('Start this problem', 'この問題を解く', '開始解題', 'c')}</a>
          <button type="button" class="btn" data-act="random">${ic('shuffle')}${t3('Surprise me', 'ランダム', '隨機', 'c')}</button></div>
      </div>
      <div class="art art-${Ink.skin()}">${Ink.hero(SETS.reduce((n, x) => n + x.n, 0))}</div>
    </section>
    <div class="cols">
      <section class="col resume"><h2>${t3('Pick up where you left off', '続きから', '繼續上次')}</h2>
        ${resume ? `<p class="hint">${esc(setMeta(resume.set).en)}</p><h3>${esc(resume.it.no)}. ${esc(resume.it.title)}</h3><p>${solved[resume.it.id] ? t3('Solved', '解いた', '已解', 'c') : t3('In progress', '取り組み中', '進行中', 'c')}</p>
          <p style="margin-top:14px"><a class="btn" href="${hrefOf(resume.set, 'problems', resume.it.id)}">${t3('Continue', '続ける', '繼續', 'c')}</a></p>`
          : `<p>${t3('Nothing opened yet. Start with the first problem.', 'まだ開いた問題はありません。最初の一問から始めましょう。', '尚未開啟任何題目，從第一題開始吧。', 'c')}</p>`}
      </section>
      ${SETS.map(setCol).join('')}
    </div>
    <footer class="foot"><span>${t3('Progress is saved in this browser only.', '進み具合はこのブラウザにだけ保存されます。', '進度只會儲存在此瀏覽器。', 'c')}</span><span>CPE26 Selection: <a href="https://cpe.mcu.edu.tw/cpelist.php">cpe.mcu.edu.tw/cpelist.php</a></span></footer></div>`;
}

/* ───────── PDF一覧・型（紙面） ───────── */
function setPills() { return `<div class="finder" role="group" aria-label="Set / セット">${SETS.map((s) => `<button type="button" class="pill" data-act="set" data-set="${s.id}" aria-pressed="${s.id === S.set}">${t3(s.en, s.ja, s.zh, 'c')}</button>`).join('')}</div>`; }
function renderPage(app) {
  const D = D_();
  if (S.view === 'pdf') {
    app.innerHTML = `<div class="paper">${mast('pdf')}<div class="toc-wrap article">
      <h1>${t3('PDFs', 'PDF一覧', 'PDF 列表')}</h1>
      <p class="dek">${t3('Open the original problem PDF, or read it on this site.', '元の問題PDFを開く、またはこのサイトで読めます。', '開啟原始題目 PDF，或在本站閱讀。', 'c')}</p>
      ${setPills()}
      <div class="finder"><div class="sbox"><span aria-hidden="true">${ic('search')}</span><label class="sr" for="q">Search</label><input id="q" type="search" autocomplete="off" placeholder="Title, UVa, ID / 題名・UVa・ID / 標題・UVa・ID" value="${esc(S.q)}"></div><span class="hint" id="pcount"></span></div>
      <div class="toc" id="pdfbody"></div></div></div>`;
    fillPdf();
  } else {
    const ex = LOOP_EX[S.set];
    const chip = (n) => { const id = exId(S.set, n); return `<a href="${hrefOf(S.set, 'problems', id)}">${id}</a>`; };
    const loopRows = [['until end of file / 個数が書いていない', 'while (cin &gt;&gt; x)', ex.eof], ['A line containing 0 ends the input', 'if (x == 0) break;', ex.zero], ['The first line contains the number of test cases', 'cin &gt;&gt; t; while (t--)', ex.t], ['line / sentence（空白を含む1行）', 'getline(cin, s)', ex.line]];
    app.innerHTML = `<div class="paper">${mast('patterns')}<article class="article">
      <h1>${t3('Patterns', '考え方の型', '解題模式')}</h1>
      <p class="dek" lang="ja">${D.items.length}問は、だいたい8つの型の組み合わせでできています。問題文を読んだら、まず5つの質問に答えて、どの型かを当てます。コードはそのあとです。</p>
      ${setPills()}
      <h2>${t3('Five questions before you code', '解く前の5つの質問', '解題前的五個問題')}</h2>
      <ol class="qlist">
        <li><div><div class="q">入力はいつ終わる？</div><p>問題文の Input の書き方で、ループの形が決まります。</p>
          <table class="tbl"><tr><th>問題文のサイン</th><th>ループの形</th><th>例</th></tr>${loopRows.map(([a, b, ns]) => `<tr><td>${a}</td><td class="mono">${b}</td><td>${ns.map(chip).join(', ')}</td></tr>`).join('')}</table></div></li>
        <li><div><div class="q">数はどれくらい大きい？</div><p>int は約21億（10桁）まで、long long は約900京（19桁）まで。それより大きい数は string で読みます。</p></div></li>
        <li><div><div class="q">何を答える問題？</div><p>「何個？」なら数える型、「順番に並べて」なら並べる型、「〜かどうか」なら判定です。答えの形を先に決めます。</p></div></li>
        <li><div><div class="q">全部試しても間に合う？</div><p>目安は 1秒でおよそ1億回（10<sup>8</sup>）。範囲が小さければ全部試すのが一番安全で、間に合わないときだけ公式を探します。</p></div></li>
        <li><div><div class="q">出力の形は？</div><p>単数と複数（operation / operations）、空行がケースの「間」か「後」か、小数は何桁か、<code>Case 1:</code> の書き方。正しく解けていても、ここを間違えると不正解になります。</p></div></li>
      </ol>
      <h2>${t3('Eight patterns', '8つの型', '八種模式')}</h2>
      <div class="pgrid">${Object.entries(TYPES).map(([k, p]) => { const mine = D.items.filter((x) => x.types.includes(k)).sort((a, b) => a.no.localeCompare(b.no));
        return `<div class="pitem" style="--pc:var(${p.color})"><h3>${t3o(p.name)}</h3><div class="one">${esc(p.one)}</div><div class="meta">サイン: ${esc(p.sig)}</div><div class="meta">${esc(p.ex)}</div><code>${esc(p.code)}</code>
          <div class="nums" aria-label="Problems">${mine.map((x) => `<button type="button" data-act="open" data-id="${x.id}" title="${esc(x.title)}">${x.no}</button>`).join('')}</div></div>`; }).join('')}</div>
      <h2>${t3('Easy first', '簡単な順', '由易到難')}</h2>
      ${TIERS.map((t, i) => { const its = D.items.filter((x) => x.tier === i + 1).sort((a, b) => a.rank - b.rank); return its.length ? `<div class="tier"><h3><span class="st">${t.lv}</span>${t3(t.en, t.ja, t.zh, 'c')}</h3><p class="why">${esc(t.why)}</p><div class="nums" style="margin-top:8px">${its.map((x) => `<button type="button" data-act="open" data-id="${x.id}" title="${esc(x.title)}">${x.no}</button>`).join('')}</div></div>` : ''; }).join('')}
    </article></div>`;
  }
}
function fillPdf() {
  const D = D_();
  const gs = D.cats.map((c) => ({ c, items: D.items.filter((x) => x.cat === c.id && matches(x, { q: S.q })).sort((a, b) => a.no.localeCompare(b.no)) })).filter((g) => g.items.length);
  $('#pdfbody').innerHTML = gs.length ? gs.map(({ c, items }) => `<h2>${t3o(c)}<span class="gc">${items.length}</span></h2>${items.map((it) => `<div class="toc-row"><span class="id">${it.id}</span><a class="ttl" href="${hrefOf(S.set, 'problems', it.id)}">${esc(it.title)}</a><span class="lead-dots"></span><span class="uva">UVa ${it.uva}</span><a class="pdf" href="${encodeURI(it.pdf)}" target="_blank" rel="noopener">PDF</a></div>`).join('')}`).join('') : '<div class="empty">No matches. / 見つかりません。 / 找不到。</div>';
  $('#pcount').textContent = `${gs.reduce((n, g) => n + g.items.length, 0)} / ${D.items.length}`;
}

/* ───────── 問題画面（LeetCode の2画面） ───────── */
function currentItem() { return D_().items.find((i) => i.id === S.id); }
function renderWorkspace(app) {
  const it = currentItem();
  const fl = flat(groups());
  const idx = fl.findIndex((x) => x.id === it.id);
  const prev = idx > 0 ? fl[idx - 1] : null, next = idx >= 0 ? fl[idx + 1] : fl[0];
  const meta = setMeta(S.set), done = solvedCount(S.set), pct = Math.round((done / meta.n) * 100);
  app.innerHTML = `<div class="ws" id="ws" data-mpane="${S.mpane}">
    <header class="wbar">
      <a class="wlogo" href="#/" aria-label="Home / 表紙">${Ink.mark()}<span>CPE Study</span></a>
      <button type="button" class="btn" data-act="list" aria-haspopup="dialog">${ic('list')}<span class="lbl">${t3('Problem List', '問題一覧', '題目列表', 'c')}</span></button>
      <button type="button" class="btn icon" data-act="prev" aria-label="Previous problem / 前の問題 / 上一題" ${prev ? '' : 'disabled'}>${ic('prev')}</button>
      <button type="button" class="btn icon" data-act="next" aria-label="Next problem / 次の問題 / 下一題" ${next ? '' : 'disabled'}>${ic('next')}</button>
      <button type="button" class="btn icon" data-act="random" aria-label="Random problem / ランダム / 隨機">${ic('shuffle')}</button>
      <span class="hint" id="pos" aria-live="polite" style="padding:0 6px;white-space:nowrap">${idx >= 0 ? idx + 1 : '–'} / ${fl.length}</span>
      <span class="grow"></span>
      <a class="btn" href="${encodeURI(it.pdf)}" target="_blank" rel="noopener">${ic('ext')}<span class="lbl">PDF</span></a>
      <button type="button" class="btn solve" id="solvebtn" data-act="solve" data-id="${it.id}" aria-pressed="${!!solved[it.id]}">${ic('check')}<span class="lbl">${t3('Solved', '解いた', '已解', 'c')}</span></button>
      <span class="wprog" id="wprog">${Ink.meter(pct, 'sm', done, meta.n, `${done} / ${meta.n}`)}<span class="txt">${done} / ${meta.n}</span></span>
      ${skinBtn()}${themeBtn()}
      <button type="button" class="btn icon" data-act="menu" aria-label="Menu / メニュー / 選單" aria-haspopup="menu">${ic('menu')}</button>
    </header>
    <div class="mseg" role="group" aria-label="Pane / 表示"><button type="button" data-act="mpane" data-p="problem" aria-pressed="${S.mpane === 'problem'}">${t3('Problem', '問題', '題目', 'c')}</button><button type="button" data-act="mpane" data-p="code" aria-pressed="${S.mpane === 'code'}">${t3('Code', 'コード', '程式碼', 'c')}</button></div>
    <div class="wmain" id="wmain" style="--split:${layout.split}%;--hsplit:${layout.hsplit}%">
      <section class="pane left" aria-label="Problem / 問題">
        <div class="pane-bar" role="tablist">${[['desc', 'Description', '問題文', '題目說明'], ['words', 'Words', '単語', '詞彙'], ['idea', 'Idea', '考え方', '想法'], ['orig', 'Original', '原文PDF', '原題 PDF']].map(([k, a, b, c]) => `<button type="button" class="tab" role="tab" data-act="ltab" data-t="${k}" aria-selected="${S.ltab === k}">${t3(a, b, c, 'c')}</button>`).join('')}</div>
        <div class="pane-body" id="lbody"></div>
      </section>
      <div class="vsep" id="vsep" role="separator" aria-orientation="vertical" aria-label="Resize panes" tabindex="0"></div>
      <div class="right">
        <section class="pane" aria-label="Code / コード">
          <div class="pane-bar"><span class="paneh">${ic('code')}${t3('Code', 'コード', '程式碼', 'c')}</span><div class="code-meta"><span class="lang">C++</span><span class="hint mono">${esc(it.id)}.cpp</span><button type="button" class="copy" data-act="copy">${ic('copy')}${t3('Copy', 'コピー', '複製', 'c')}</button></div></div>
          <div class="pane-body"><pre class="src" id="code"></pre></div>
        </section>
        <div class="hsep" id="hsep" role="separator" aria-orientation="horizontal" aria-label="Resize panes" tabindex="0"></div>
        <section class="pane" aria-label="Sample / サンプル">
          <div class="pane-bar" role="tablist">${[['sample', 'Sample', 'サンプル', '範例'], ['run', 'Run locally', '手元で実行', '本機執行']].map(([k, a, b, c]) => `<button type="button" class="tab" role="tab" data-act="rtab" data-t="${k}" aria-selected="${S.rtab === k}">${t3(a, b, c, 'c')}</button>`).join('')}</div>
          <div class="pane-body" id="rbody"></div>
        </section>
      </div>
    </div>
  </div>`;
  fillLeft(it); fillCode(it); fillRight(it);
}

function fillLeft(it) {
  const body = $('#lbody'), st = it.stmt;
  $$('.tab[data-act="ltab"]').forEach((b) => b.setAttribute('aria-selected', String(b.dataset.t === S.ltab)));
  const title = `<h1 class="ptitle"><span class="no">${esc(it.no)}.</span><span>${esc(it.title)}</span><span id="hk">${solved[it.id] ? Ink.badge() : ''}</span></h1>
    <div class="chips">${lvChip(it)}<span class="chip">UVa ${it.uva}</span>${typeChips(it)}</div>`;
  if (S.ltab === 'desc') {
    const terms = st.vocab.map((v) => v.en).filter(Boolean).sort((a, b) => b.length - a.length);
    const meaning = Object.fromEntries(st.vocab.map((v) => [v.en.toLowerCase(), v.ja]));
    const re = terms.length ? new RegExp('(' + terms.map((t) => t.replace(/[.*+?^${}()|[\]\\]/g, '\\$&')).join('|') + ')', 'gi') : null;
    const secs = [['statement', 'Problem', '問題文', '題目'], ['input', 'Input', '入力', '輸入'], ['output', 'Output', '出力', '輸出']];
    const wrap = document.createElement('div');
    wrap.className = 'prose'; if (S.lang === 'ja') wrap.lang = 'ja';
    secs.forEach(([k, a, b, c]) => {
      const h = document.createElement('h3'); h.innerHTML = t3(a, b, c, S.lang === 'ja' ? 'c' : ''); wrap.append(h);
      st[k].forEach(({ en, ja }) => {
        const p = document.createElement('p');
        if (S.lang === 'ja') { p.textContent = ja || en || ''; }
        else if (!re) p.textContent = en;
        else en.split(re).forEach((part, i) => { if (i % 2) { const s = document.createElement('span'); s.className = 'vw'; s.textContent = part; s.title = meaning[part.toLowerCase()] || ''; p.append(s); } else if (part) p.append(part); });
        wrap.append(p);
      });
    });
    body.innerHTML = `<div class="desc">${title}
      <div class="langsw" role="group" aria-label="Language / 言語"><button type="button" data-act="lang" data-l="en" aria-pressed="${S.lang === 'en'}">English</button><button type="button" data-act="lang" data-l="ja" aria-pressed="${S.lang === 'ja'}">日本語</button></div>
      ${st.note ? `<div class="note"></div>` : ''}<div id="prose"></div></div>`;
    $('#prose', body).replaceWith(wrap);
    if (st.note) $('.note', body).textContent = st.note;
  } else if (S.ltab === 'words') {
    body.innerHTML = `<div class="desc">${title}<h3 class="prose" style="margin-top:22px;font-family:var(--serif)">${t3('Vocabulary', '単語', '詞彙')}</h3><div class="vtbl"><table>${st.vocab.map((v) => `<tr><td>${esc(v.en)}</td><td>${esc(v.ja)}${v.note ? `<div class="vnote">${esc(v.note)}</div>` : ''}</td></tr>`).join('')}</table></div></div>`;
  } else if (S.ltab === 'idea') {
    body.innerHTML = `<div class="desc">${title}<h3 class="prose" style="margin-top:22px;font-family:var(--serif)">${t3('Idea', '考え方', '想法')}</h3><p class="idea">${esc(it.idea)}</p>
      ${it.types.map((k) => `<div class="patt" style="--pc:var(${TYPES[k].color})"><h4>${t3o(TYPES[k].name)}</h4><p>${esc(TYPES[k].one)}</p><code>${esc(TYPES[k].code)}</code></div>`).join('')}</div>`;
  } else {
    body.innerHTML = `<div class="desc">${title}<p class="openpdf"><a class="btn" href="${encodeURI(it.pdf)}" target="_blank" rel="noopener">${ic('ext')}${t3('Open PDF', 'PDFを開く', '開啟 PDF', 'c')}</a></p>
      <div class="sheet">${Array.from({ length: it.pages }, (_, i) => `<img src="problems/${it.id}-${i + 1}.png" alt="${esc(it.id)} ${esc(it.title)} (PDF page ${i + 1})" ${i ? 'loading="lazy"' : ''}>`).join('')}</div></div>`;
  }
  body.scrollTop = 0;
}

// C++ の簡易ハイライト（行ごと）
const KW = new Set('if else for while do switch case break continue return using namespace const static auto struct class public private new delete true false nullptr sizeof typedef template typename operator inline constexpr default goto'.split(' '));
const TY = new Set('int long short char bool void double float unsigned signed string vector map set unordered_map unordered_set pair array deque queue stack priority_queue bitset size_t cin cout cerr endl istringstream ostringstream stringstream ios sync_with_stdio tie getline sort min max abs swap'.split(' '));
const TOK = /(\/\/.*$)|("(?:\\.|[^"\\])*")|('(?:\\.|[^'\\])+')|(^\s*#\s*\w+(?:\s*<[^>]*>)?)|(\b\d+(?:\.\d+)?(?:[eE][+-]?\d+)?(?:LL|ll|ULL|ull|u|U|f)?\b)|([A-Za-z_]\w*)/g;
function highlight(line) {
  let out = '', last = 0, m;
  TOK.lastIndex = 0;
  while ((m = TOK.exec(line))) {
    out += esc(line.slice(last, m.index));
    const s = esc(m[0]);
    if (m[1]) out += `<span class="tk-cm">${s}</span>`;
    else if (m[2] || m[3]) out += `<span class="tk-st">${s}</span>`;
    else if (m[4]) out += `<span class="tk-pp">${s}</span>`;
    else if (m[5]) out += `<span class="tk-nu">${s}</span>`;
    else if (KW.has(m[6])) out += `<span class="tk-kw">${s}</span>`;
    else if (TY.has(m[6])) out += `<span class="tk-ty">${s}</span>`;
    else out += s;
    last = m.index + m[0].length;
  }
  return out + esc(line.slice(last));
}
function fillCode(it) {
  $('#code').innerHTML = it.code.split('\n').map((l) => `<span class="l">${highlight(l) || ' '}</span>`).join('');
}
const cmdOf = (it) => `g++-15 -std=c++17 -o sol answers/${it.id}.cpp && ./sol < answers/samples/${it.id}.in`;
function fillRight(it) {
  $$('.tab[data-act="rtab"]').forEach((b) => b.setAttribute('aria-selected', String(b.dataset.t === S.rtab)));
  const f = (k, label) => `<div class="field"><div class="lab"><span>${label}</span><button type="button" class="copy" data-act="copytext" data-k="${k}">${ic('copy')}${t3('Copy', 'コピー', '複製', 'c')}</button></div><pre id="f-${k}"></pre></div>`;
  $('#rbody').innerHTML = S.rtab === 'sample'
    ? `<div class="sample">${f('in', t3('Input', '入力', '輸入', 'c'))}${f('out', t3('Expected output', '期待する出力', '預期輸出', 'c'))}</div>`
    : `<div class="sample"><div class="field"><div class="lab"><span>${t3('Terminal', 'ターミナル', '終端機', 'c')}</span><button type="button" class="copy" data-act="copytext" data-k="cmd">${ic('copy')}${t3('Copy', 'コピー', '複製', 'c')}</button></div><div class="cmd" id="f-cmd"></div></div>
       <p class="hint">${t3('Run it from the repository root. On macOS use g++-15 (the default clang has no bits/stdc++.h).', 'リポジトリのルートで実行します。macOS では g++-15 を使います（標準の clang には bits/stdc++.h がありません）。', '請在儲存庫根目錄執行。macOS 請使用 g++-15。', 'c')}</p></div>`;
  if (S.rtab === 'sample') { $('#f-in').textContent = it.sample.in; $('#f-out').textContent = it.sample.out; } else $('#f-cmd').textContent = cmdOf(it);
}

/* ───────── 引き出し: Problem List ───────── */
function openDrawer() {
  S.drawer = true; S.pop = null;
  $('#layer').innerHTML = `<div class="scrim" data-act="close"></div>
    <aside class="drawer" role="dialog" aria-modal="true" aria-label="Problem List / 問題一覧">
      <div class="dh"><h2>${t3('Problem List', '問題一覧', '題目列表', 'c')}</h2><div class="cnt" id="dcnt"></div><button type="button" class="btn icon" data-act="close" aria-label="Close / 閉じる / 關閉">${ic('x')}</button></div>
      <div class="dctl">
        <div class="srow"><div class="sbox"><span aria-hidden="true">${ic('search')}</span><label class="sr" for="dq">Search questions</label><input id="dq" type="search" autocomplete="off" placeholder="Search questions / 検索 / 搜尋" value="${esc(S.q)}"></div>
          <button type="button" class="btn icon" data-act="filter" aria-expanded="${S.filterOpen}" aria-label="Filter and sort / 絞り込み・並び替え / 篩選與排序">${ic('filter')}</button></div>
        <div id="fp"></div>
      </div>
      <div class="dlist" id="dlist"></div>
    </aside>`;
  fillFilter(); fillDrawerList(true);
  if (S.focusSearch) { $('#dq').focus(); S.focusSearch = false; }
}
function fillFilter() {
  const fp = $('#fp'); if (!fp) return;
  if (!S.filterOpen) { fp.innerHTML = ''; return; }
  fp.innerHTML = `<div class="fpanel">
    <div class="grp"><div class="lab">${t3('Set', 'セット', '題組', 'c')}</div><div class="wrap">${SETS.map((s) => `<button type="button" class="pill" data-act="dset" data-set="${s.id}" aria-pressed="${s.id === S.set}">${t3(s.en, s.ja, s.zh, 'c')}</button>`).join('')}</div></div>
    <div class="grp"><div class="lab">${t3('Order', '並び順', '排序', 'c')}</div><select id="dorder" aria-label="Order"><option value="cat"${S.order === 'cat' ? ' selected' : ''}>By category / カテゴリ別 / 依分類</option><option value="no"${S.order === 'no' ? ' selected' : ''}>By number / 番号順 / 依編號</option><option value="rank"${S.order === 'rank' ? ' selected' : ''}>Easy first / 簡単な順 / 由易到難</option></select></div>
    <div class="grp"><div class="lab">${t3('Level', '難しさ', '難度', 'c')}</div><div class="wrap">${[1, 2, 3, 4].map((n) => `<button type="button" class="pill" data-act="dtier" data-n="${n}" aria-pressed="${S.tier === n}">${TIERS[n - 1].lv} ${esc(TIERS[n - 1].en)}</button>`).join('')}</div></div>
    <div class="grp"><div class="lab">${t3('Pattern', '型', '模式', 'c')}</div><div class="wrap">${Object.keys(TYPES).map((k) => `<button type="button" class="pill" data-act="dtype" data-k="${k}" aria-pressed="${S.type === k}">${esc(TYPES[k].name.en)}</button>`).join('')}</div></div>
    <button type="button" class="pill" data-act="dunsolved" aria-pressed="${S.unsolved}" style="justify-self:start">${t3('Unsolved only', '未解決だけ', '僅顯示未解', 'c')}</button></div>`;
}
function fillDrawerList(reveal) {
  const list = $('#dlist'); if (!list) return;
  const gs = groups(), fl = flat(gs), done = solvedCount(S.set), meta = setMeta(S.set);
  $('#dcnt').innerHTML = `${Ink.meter(Math.round((done / meta.n) * 100), 'sm', done, meta.n, '')}<span>${done} / ${meta.n} ${t3('solved', '解いた', '已解', 'en-only')}</span>`;
  if (!fl.length) { list.innerHTML = '<div class="empty">No matches. / 見つかりません。 / 找不到。</div>'; return; }
  list.innerHTML = gs.map((g) => `${g.head ? `<div class="gh">${g.head}</div>` : ''}${g.items.map((it) => `<button type="button" class="row" data-act="pick" data-id="${it.id}"${S.view === 'problems' && it.id === S.id ? ' aria-current="true"' : ''}>
      <span class="ok">${solved[it.id] ? ic('check') : ''}</span><span class="tt"><span class="no">${esc(it.no)}.</span>${esc(it.title)}</span><span class="lv" data-l="${it.tier}">${LEVELS[it.tier].short}</span></button>`).join('')}`).join('');
  if (reveal) { const cur = $('.row[aria-current="true"]', list); if (cur) cur.scrollIntoView({ block: 'center' }); }
}
function closeLayer() { S.drawer = false; S.pop = null; const l = $('#layer'); if (l) l.innerHTML = ''; }

function openMenu(btn) {
  const r = btn.getBoundingClientRect();
  S.pop = 'menu';
  $('#layer').innerHTML = `<div class="scrim" data-act="close" style="background:transparent"></div><div class="pop" role="menu" style="top:${r.bottom + 6}px;right:${Math.max(8, innerWidth - r.right)}px">
    <a role="menuitem" href="#/">${ic('home')}${t3('Front page', '表紙', '首頁', 'c')}</a>
    <a role="menuitem" href="${hrefOf(S.set, 'patterns')}">${ic('code')}${t3('Patterns', '考え方の型', '解題模式', 'c')}</a>
    <a role="menuitem" href="${hrefOf(S.set, 'pdf')}">${ic('ext')}${t3('PDFs', 'PDF一覧', 'PDF 列表', 'c')}</a>
    ${SETS.filter((s) => s.id !== S.set).map((s) => `<button type="button" role="menuitem" data-act="set" data-set="${s.id}">${ic('shuffle')}${t3('Switch to ' + s.en, s.ja + 'へ', '切換到' + s.zh, 'c')}</button>`).join('')}
    <div class="hint" style="padding:8px 12px">← → / j k : prev / next &nbsp; / : search &nbsp; s : solved</div></div>`;
}

/* ───────── 操作 ───────── */
function move(dir) {
  if (S.view !== 'problems') return;
  const fl = flat(groups());
  const idx = fl.findIndex((x) => x.id === S.id);
  const to = idx < 0 ? fl[0] : fl[idx + dir];
  if (to) go(S.set, 'problems', to.id);
}
function randomPick() {
  const D = D_(); const pool = D.items.filter((x) => !solved[x.id] && x.id !== S.id);
  const list = pool.length ? pool : D.items;
  go(S.set, 'problems', list[Math.floor(Math.random() * list.length)].id);
}
function toggleSolved(id, on) {
  const v = on === undefined ? !solved[id] : on;
  if (v) solved[id] = true; else delete solved[id];
  store.set('cpe:solved', solved);
  if (S.view === 'problems') {
    const b = $('#solvebtn'); if (b) b.setAttribute('aria-pressed', String(!!solved[id]));
    const hk = $('#hk'); if (hk && id === S.id) hk.innerHTML = v ? Ink.badge('stamp-in') : '';
    const meta = setMeta(S.set), done = solvedCount(S.set);
    const wp = $('#wprog'); if (wp) wp.innerHTML = `${Ink.meter(Math.round((done / meta.n) * 100), 'sm', done, meta.n, `${done} / ${meta.n}`)}<span class="txt">${done} / ${meta.n}</span>`;
  }
  if (S.drawer) fillDrawerList();
}
function copyText(text, btn) {
  const label = btn.innerHTML;
  const done = () => { btn.textContent = '✓'; setTimeout(() => { btn.innerHTML = label; }, 1300); };
  (navigator.clipboard ? navigator.clipboard.writeText(text) : Promise.reject()).then(done, () => { btn.textContent = '⌘C'; });
}
function refreshNav() {
  if (S.view !== 'problems') return;
  const fl = flat(groups()), it = currentItem(), idx = fl.findIndex((x) => x.id === it.id);
  const prev = idx > 0, next = idx >= 0 ? idx < fl.length - 1 : fl.length > 0;
  const p = $('[data-act="prev"]'), n = $('[data-act="next"]'); if (p) p.disabled = !prev; if (n) n.disabled = !next;
  const pos = $('#pos'); if (pos) pos.textContent = `${idx >= 0 ? idx + 1 : '–'} / ${fl.length}`;
}
const rerenderList = () => { if (S.drawer) fillDrawerList(); refreshNav(); };

document.addEventListener('click', (e) => {
  const el = e.target.closest('[data-act]'); if (!el) return;
  const a = el.dataset.act;
  if (a === 'set') go(el.dataset.set, S.view === 'home' ? 'problems' : S.view, null);
  else if (a === 'dset') { S.reopen = true; go(el.dataset.set, 'problems', null); }
  else if (a === 'list') { S.focusSearch = false; ensureSet(S.set).then(openDrawer); }
  else if (a === 'close') closeLayer();
  else if (a === 'filter') { S.filterOpen = !S.filterOpen; el.setAttribute('aria-expanded', String(S.filterOpen)); fillFilter(); }
  else if (a === 'pick' || a === 'open') go(S.set, 'problems', el.dataset.id);
  else if (a === 'prev') move(-1);
  else if (a === 'next') move(1);
  else if (a === 'random') randomPick();
  else if (a === 'solve') toggleSolved(el.dataset.id);
  else if (a === 'theme') toggleTheme();
  else if (a === 'skin') openSkinMenu(el);
  else if (a === 'setskin') setSkin(el.dataset.s);
  else if (a === 'menu') openMenu(el);
  else if (a === 'ltab') { S.ltab = el.dataset.t; fillLeft(currentItem()); }
  else if (a === 'rtab') { S.rtab = el.dataset.t; fillRight(currentItem()); }
  else if (a === 'lang') { S.lang = el.dataset.l; fillLeft(currentItem()); }
  else if (a === 'mpane') { S.mpane = el.dataset.p; $('#ws').dataset.mpane = S.mpane; $$('.mseg button').forEach((b) => b.setAttribute('aria-pressed', String(b.dataset.p === S.mpane))); }
  else if (a === 'copy') copyText(currentItem().code, el);
  else if (a === 'copytext') { const it = currentItem(); copyText(el.dataset.k === 'in' ? it.sample.in : el.dataset.k === 'out' ? it.sample.out : cmdOf(it), el); }
  else if (a === 'dtier') { S.tier = S.tier === +el.dataset.n ? 0 : +el.dataset.n; fillFilter(); rerenderList(); }
  else if (a === 'dtype') { S.type = S.type === el.dataset.k ? null : el.dataset.k; fillFilter(); rerenderList(); }
  else if (a === 'dunsolved') { S.unsolved = !S.unsolved; fillFilter(); rerenderList(); }
});
document.addEventListener('input', (e) => {
  const t = e.target;
  if (t.id === 'dq') { S.q = t.value; rerenderList(); }
  else if (t.id === 'q' && S.view === 'pdf') { S.q = t.value; fillPdf(); }
});
document.addEventListener('change', (e) => { if (e.target.id === 'dorder') { S.order = e.target.value; rerenderList(); } });
document.addEventListener('keydown', (e) => {
  if (e.key === 'Escape') { if (S.drawer || S.pop) closeLayer(); return; }
  const tag = (e.target.tagName || '').toLowerCase();
  if (tag === 'input' || tag === 'textarea' || tag === 'select' || e.target.isContentEditable || e.metaKey || e.ctrlKey || e.altKey) return;
  const sep = e.target.closest && e.target.closest('#vsep,#hsep');
  if (sep) {
    const kind = sep.id === 'vsep' ? 'v' : 'h';
    const dec = kind === 'v' ? 'ArrowLeft' : 'ArrowUp', inc = kind === 'v' ? 'ArrowRight' : 'ArrowDown';
    if (e.key === dec) { e.preventDefault(); setSplit(kind, (kind === 'v' ? layout.split : layout.hsplit) - 3); }
    else if (e.key === inc) { e.preventDefault(); setSplit(kind, (kind === 'v' ? layout.split : layout.hsplit) + 3); }
    return;
  }
  if (e.key === '/') { e.preventDefault(); if (S.view === 'pdf') { const q = $('#q'); if (q) q.focus(); } else { S.focusSearch = true; ensureSet(S.set).then(openDrawer); } }
  else if (S.view === 'problems') {
    if (e.key === 'ArrowRight' || e.key === 'j') move(1);
    else if (e.key === 'ArrowLeft' || e.key === 'k') move(-1);
    else if (e.key === 's') toggleSolved(S.id);
  }
});

/* 画面分割をドラッグ・キーボードで変える */
function setSplit(kind, v) {
  const w = $('#wmain'); if (!w) return;
  if (kind === 'v') { layout.split = Math.max(26, Math.min(72, v)); w.style.setProperty('--split', layout.split + '%'); }
  else { layout.hsplit = Math.max(25, Math.min(85, v)); w.style.setProperty('--hsplit', layout.hsplit + '%'); }
  store.set('cpe:layout', layout);
}
document.addEventListener('pointerdown', (e) => {
  const sep = e.target.closest('#vsep,#hsep'); if (!sep) return;
  e.preventDefault();
  const kind = sep.id === 'vsep' ? 'v' : 'h';
  const box = (kind === 'v' ? $('#wmain') : $('.right')).getBoundingClientRect();
  sep.classList.add('dragging'); sep.setPointerCapture(e.pointerId);
  const mv = (ev) => setSplit(kind, kind === 'v' ? ((ev.clientX - box.left) / box.width) * 100 : ((ev.clientY - box.top) / box.height) * 100);
  const up = () => { sep.classList.remove('dragging'); sep.removeEventListener('pointermove', mv); sep.removeEventListener('pointerup', up); };
  sep.addEventListener('pointermove', mv); sep.addEventListener('pointerup', up);
});

window.addEventListener('hashchange', applyRoute);
applyRoute();
})();
