/* CPE Study — 49問と26選集を1ページで読む学習アプリ（ビルド不要・静的ファイルのみ）
 * データ: data/types.js（8つの型）, data/cpe49.js, data/cpe26.js（切り替え時に読み込む）
 * URL:    #/<set>/<tab>[/<id>]   例) #/26/problems/CPE26-044
 */
(() => {
'use strict';

const SETS = [
  { id: '49', en: 'CPE 49', ja: 'CPE 49問', zh: 'CPE 49題', n: 49 },
  { id: '26', en: 'CPE26 Selection', ja: 'CPE26選集', zh: 'CPE26選集', n: 56 },
];
const TABS = [
  { id: 'problems', en: 'Problems', ja: '問題', zh: '題目' },
  { id: 'pdf', en: 'PDFs', ja: 'PDF一覧', zh: 'PDF 列表' },
  { id: 'patterns', en: 'Patterns', ja: '考え方の型', zh: '解題模式' },
];
const TIERS = [
  { lv: '★', en: 'First steps', ja: 'はじめの一歩', zh: '入門', why: '入力を読んで、式1本かループ1つで答えが出る。' },
  { lv: '★★', en: 'Loops & arrays', ja: 'ループと配列', zh: '迴圈與陣列', why: '% 10、配列で数える、sort など、型を1つ使えば解ける。' },
  { lv: '★★★', en: 'Combining patterns', ja: '型を組み合わせる', zh: '組合模式', why: '型を2つ組み合わせる。または出力の形にひと工夫いる。' },
  { lv: '★★★★', en: 'Tricky ones', ja: '落とし穴が多い', zh: '陷阱較多', why: '公式を自分で作る、小数の誤差、ルールが細かい、のどれかがある。' },
];
// 「入力はいつ終わる？」の例（問題番号）
const LOOP_EX = {
  '49': { eof: [2, 15, 24], zero: [5, 10, 35], t: [1, 19, 20], line: [7, 8, 12, 43] },
  '26': { eof: [101, 111, 121], zero: [41, 42, 51], t: [12, 43, 113], line: [24, 133, 143] },
};
const exId = (set, n) => (set === '49' ? `CPE49-${String(n).padStart(2, '0')}` : `CPE26-${String(n).padStart(3, '0')}`);

const TYPES = window.CPE_TYPES || {};
const $ = (sel, root = document) => root.querySelector(sel);
const esc = (s) => String(s).replace(/[&<>"']/g, (c) => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;' }[c]));
const t3 = (en, ja, zh, cls = '') => `<span class="t3 ${cls}"><span class="en">${esc(en)}</span><span class="ja">${esc(ja)}</span><span class="zh">${esc(zh)}</span></span>`;
const t3o = (o, cls = '') => t3(o.en, o.ja, o.zh, cls);
const store = {
  get(k, d) { try { const v = localStorage.getItem(k); return v == null ? d : JSON.parse(v); } catch { return d; } },
  set(k, v) { try { localStorage.setItem(k, JSON.stringify(v)); } catch { /* 保存できない環境でも動く */ } },
};

const S = { set: '49', tab: 'problems', id: null, q: '', type: null, tier: 0, unsolved: false, order: 'no' };
let solved = store.get('cpe:solved', {});
const data = {};
const fold = { ja: false, text: false };
let codeOpen = false;
const wide = matchMedia('(min-width: 1200px)');

/* ───────── データ読み込み（切り替え時に1セットずつ） ───────── */
function ensureSet(id) {
  if (data[id]) return Promise.resolve(data[id]);
  return new Promise((resolve, reject) => {
    const s = document.createElement('script');
    s.src = `data/cpe${id}.js`;
    s.onload = () => { data[id] = window.CPE_SETS[id]; resolve(data[id]); };
    s.onerror = () => reject(new Error(`failed to load ${s.src}`));
    document.head.append(s);
  });
}

/* ───────── ルーティング ───────── */
const hrefOf = (set, tab, id) => `#/${set}/${tab}${id ? '/' + encodeURIComponent(id) : ''}`;
function parseHash() {
  const m = location.hash.match(/^#\/(49|26)\/(problems|pdf|patterns)(?:\/([^/]+))?$/);
  if (m) return { set: m[1], tab: m[2], id: m[3] ? decodeURIComponent(m[3]) : null };
  const v = store.get('cpe:view', null);
  return v && SETS.some((s) => s.id === v.set) ? { set: v.set, tab: v.tab, id: null } : { set: '49', tab: 'problems', id: null };
}
function go(set, tab, id) {
  const h = hrefOf(set, tab, id);
  if (location.hash === h) applyRoute(); else location.hash = h;
}

async function applyRoute() {
  const r = parseHash();
  const setChanged = r.set !== S.set;
  S.set = r.set; S.tab = r.tab;
  if (setChanged) { S.q = ''; S.type = null; S.tier = 0; S.unsolved = false; S.order = 'no'; }
  store.set('cpe:view', { set: S.set, tab: S.tab });
  document.body.classList.remove('drawer-open');
  renderTop();
  if (!data[S.set]) { $('#main').innerHTML = '<p class="loading">Loading… / 読み込み中… / 載入中…</p>'; $('#side').innerHTML = ''; }
  try { await ensureSet(S.set); } catch (e) {
    $('#main').innerHTML = `<p class="loading">Failed to load data. Reload the page. / データを読み込めませんでした。再読み込みしてください。</p>`;
    return;
  }
  const D = data[S.set];
  if (r.id && D.items.some((i) => i.id === r.id)) S.id = r.id;
  else if (S.tab === 'problems') {
    const last = store.get('cpe:last:' + S.set, null);
    S.id = D.items.some((i) => i.id === last) ? last : D.items[0].id;
    history.replaceState(null, '', hrefOf(S.set, S.tab, S.id));
  }
  if (S.tab === 'problems') store.set('cpe:last:' + S.set, S.id);
  render();
  const other = SETS.find((s) => s.id !== S.set).id;
  (window.requestIdleCallback || ((f) => setTimeout(f, 1500)))(() => ensureSet(other).catch(() => {}));
}

/* ───────── 絞り込み ───────── */
const D_ = () => data[S.set];
function matches(it, f) {
  if (f.q) {
    const q = f.q.toLowerCase();
    const hay = `${it.id} ${it.no} ${it.title} uva${it.uva} ${it.uva}`.toLowerCase();
    if (!q.split(/\s+/).every((w) => hay.includes(w))) return false;
  }
  if (f.type && !it.types.includes(f.type)) return false;
  if (f.tier && it.tier !== f.tier) return false;
  if (f.unsolved && solved[it.id]) return false;
  return true;
}
function groups(filter) {
  const D = D_();
  if (S.order === 'rank') {
    return TIERS.map((t, i) => ({
      key: 't' + (i + 1), head: `<span class="mono lvs">${t.lv}</span> ${t3(t.en, t.ja, t.zh, 'compact')}`,
      items: D.items.filter((x) => x.tier === i + 1 && matches(x, filter)).sort((a, b) => a.rank - b.rank),
    })).filter((g) => g.items.length);
  }
  return D.cats.map((c) => ({
    key: c.id, head: t3(c.en, c.ja, c.zh, 'compact'),
    items: D.items.filter((x) => x.cat === c.id && matches(x, filter)).sort((a, b) => a.no.localeCompare(b.no)),
  })).filter((g) => g.items.length);
}
const flat = (gs) => gs.flatMap((g) => g.items);
const typeTag = (k) => `<span class="tag" style="--pc:var(${TYPES[k].color})">${t3o(TYPES[k].name, 'compact')}</span>`;
const stars = (n) => '★'.repeat(n);

/* ───────── 上部バー ───────── */
function renderTop() {
  $('#setseg').innerHTML = SETS.map((s) => `<button type="button" role="tab" aria-selected="${s.id === S.set}" data-act="set" data-set="${s.id}">${t3(s.en, s.ja, s.zh, 'compact')}<span class="n">${s.n}</span></button>`).join('');
  $('#tabs').innerHTML = TABS.map((t) => `<button type="button" role="tab" aria-selected="${t.id === S.tab}" data-act="tab" data-tab="${t.id}">${t3(t.en, t.ja, t.zh, 'compact')}</button>`).join('');
  document.body.classList.toggle('no-side-ui', S.tab !== 'problems');
  $('#shell').classList.toggle('no-side', S.tab !== 'problems');
  renderProgress();
}
function renderProgress() {
  const meta = SETS.find((s) => s.id === S.set);
  const done = Object.keys(solved).filter((k) => solved[k] && k.startsWith(`CPE${S.set}-`)).length;
  $('#progress').innerHTML = `<span>${done} / ${meta.n} ${t3('solved', '解いた', '已解', 'compact')}</span><progress max="${meta.n}" value="${done}" aria-label="Progress"></progress>`;
}

/* ───────── サイドバー ───────── */
function renderSide(force) {
  const side = $('#side');
  if (S.tab !== 'problems') { side.innerHTML = ''; delete side.dataset.built; return; }
  if (!force && side.dataset.built === S.set) { renderList(true); return; }  // 問題を移動しただけなら一覧は作り直さない
  side.dataset.built = S.set;
  side.innerHTML = `
    <div class="side-head">
      <div class="search"><label class="sr" for="q">Search / 検索 / 搜尋</label>
        <input id="q" type="search" autocomplete="off" placeholder="Title, UVa, ID / 題名・UVa・ID / 標題・UVa・ID" value="${esc(S.q)}"><kbd aria-hidden="true">/</kbd></div>
      <div class="chips" role="group" aria-label="Pattern filter / 型で絞り込み">${Object.keys(TYPES).map((k) =>
        `<button type="button" class="chip" style="--pc:var(${TYPES[k].color})" data-act="type" data-type="${k}" aria-pressed="${S.type === k}">${t3o(TYPES[k].name, 'compact')}</button>`).join('')}</div>
      <div class="row2">
        <select id="tier" aria-label="Level / 難しさ / 難度"><option value="0">All levels</option>${TIERS.map((t, i) => `<option value="${i + 1}"${S.tier === i + 1 ? ' selected' : ''} title="${esc(t.ja)} / ${esc(t.zh)}">${t.lv} ${esc(t.en)}</option>`).join('')}</select>
        <select id="order" aria-label="Order / 並び順 / 排序"><option value="no"${S.order === 'no' ? ' selected' : ''} title="番号順 / 依編號">By number</option><option value="rank"${S.order === 'rank' ? ' selected' : ''} title="簡単な順 / 由易到難">Easy first</option></select>
      </div>
      <button type="button" class="toggle" id="unsolved" data-act="unsolved" aria-pressed="${S.unsolved}">Unsolved only / 未解決だけ / 僅顯示未解</button>
      <div class="count" id="count"></div>
    </div>
    <div class="list" id="list"></div>`;
  renderList(true);
}
function filterActive() { return !!(S.q || S.type || S.tier || S.unsolved); }
function renderList(reveal) {
  const gs = groups(S);
  const fl = flat(gs);
  const total = D_().items.length;
  $('#count').innerHTML = `<span>${fl.length} / ${total}</span>${filterActive() ? '<button type="button" class="link-btn" data-act="clear">Clear / クリア / 清除</button>' : ''}`;
  const list = $('#list');
  if (!fl.length) { list.innerHTML = '<div class="empty">No matches. / 見つかりません。 / 找不到。</div>'; return; }
  const open = filterActive() || S.order === 'rank';
  list.innerHTML = gs.map((g) => `<details class="group"${open || g.items.some((i) => i.id === S.id) ? ' open' : ''}><summary>${g.head}<span class="gc">${g.items.length}</span></summary>${g.items.map((it) => `
    <div class="item${solved[it.id] ? ' is-solved' : ''}" ${it.id === S.id ? 'aria-current="true"' : ''}>
      <button type="button" class="pick" data-act="pick" data-id="${it.id}" ${it.id === S.id ? 'aria-current="true"' : ''}><span class="pn">${it.no}</span><span class="pt">${esc(it.title)}</span><span class="lv" aria-label="${it.tier} stars">${stars(it.tier)}</span></button>
      <input type="checkbox" class="done" data-id="${it.id}" ${solved[it.id] ? 'checked' : ''} aria-label="Solved / 解いた: ${esc(it.title)}" title="Solved / 解いた / 已解">
    </div>`).join('')}</details>`).join('');
  const cur = $('.item[aria-current="true"]', list);
  if (reveal && cur) cur.scrollIntoView({ block: 'nearest' });
}

/* ───────── メイン ───────── */
function render() {
  renderTop();
  renderSide();
  if (S.tab === 'problems') renderProblem();
  else if (S.tab === 'pdf') renderPdf();
  else renderPatterns();
  const it = D_().items.find((i) => i.id === S.id);
  document.title = S.tab === 'problems' && it ? `${it.id} ${it.title} · CPE Study` : 'CPE Study · CPE 学習 · CPE 學習';
}

function renderProblem() {
  const D = D_();
  const it = D.items.find((i) => i.id === S.id);
  const fl = flat(groups(S));
  const idx = fl.findIndex((x) => x.id === it.id);
  const prev = idx > 0 ? fl[idx - 1] : null;
  const next = idx >= 0 ? fl[idx + 1] : fl[0];
  const hadFocus = document.activeElement && document.activeElement.closest && document.activeElement.closest('.pager') ? document.activeElement.dataset.act : null;
  const main = $('#main');
  main.innerHTML = `
    <p class="eyebrow">${esc(it.id)} · UVa ${it.uva} · ${stars(it.tier)}</p>
    <div class="head"><h2>${esc(it.title)}</h2>
      <div class="actions">
        <a class="btn primary" href="${encodeURI(it.pdf)}" target="_blank" rel="noopener">${t3('Open PDF', 'PDFを開く', '開啟 PDF', 'compact')} ↗</a>
        <button type="button" class="btn ok" data-act="solve" data-id="${it.id}" aria-pressed="${!!solved[it.id]}">${solved[it.id] ? '✓ ' : ''}${t3('Solved', '解いた', '已解', 'compact')}</button>
      </div></div>
    <div class="tags">${it.types.map(typeTag).join('')}</div>
    <nav class="pager" aria-label="Problem pager / 問題の移動">
      <button type="button" class="btn" data-act="prev" ${prev ? '' : 'disabled'}>← ${t3('Prev', '前へ', '上一題', 'compact')}</button>
      <div class="pos"><strong id="pos" aria-live="polite">${idx >= 0 ? idx + 1 : '–'} / ${fl.length}</strong>
        <select id="jump" aria-label="Jump to / 移動 / 跳到">${fl.map((x) => `<option value="${x.id}"${x.id === it.id ? ' selected' : ''}>${x.no} ${esc(x.title)}</option>`).join('')}${idx < 0 ? `<option value="${it.id}" selected>${it.no} ${esc(it.title)}</option>` : ''}</select>
        <span class="hint">${idx >= 0 && !next ? '<span class="end">Last problem / 最後の問題です</span>' : '← → / j k'}</span></div>
      <button type="button" class="btn" data-act="next" ${next ? '' : 'disabled'}>${t3('Next', '次へ', '下一題', 'compact')} →</button>
    </nav>
    <div class="split"><div class="left">
      <div class="sheet" id="sheet"></div>
      <div class="note" id="note" hidden></div>
      <div class="blk"><div class="lbl">${t3('Vocabulary', '単語', '詞彙')}</div><div class="vtbl"><table class="vocab" id="vocab"></table></div></div>
      <details class="fold" data-k="ja"><summary>${t3('Japanese translation', '日本語訳を見る', '日文翻譯')}</summary><div class="inner prose">
        <h4>Problem <span>問題文</span></h4><div id="ja-st"></div><h4>Input <span>入力</span></h4><div id="ja-in"></div><h4>Output <span>出力</span></h4><div id="ja-out"></div></div></details>
      <details class="fold" data-k="text"><summary>${t3('Text version (words underlined)', 'テキスト版（英文・単語に下線）', '文字版（單字加底線）')}</summary><div class="inner prose">
        <h4>Problem</h4><div id="en-st"></div><h4>Input</h4><div id="en-in"></div><h4>Output</h4><div id="en-out"></div></div></details>
      <div class="blk two"><div><div class="lbl">Sample Input</div><pre class="io" id="sin"></pre></div><div><div class="lbl">Sample Output</div><pre class="io" id="sout"></pre></div></div>
      <details class="fold"><summary>${t3('Idea', '考え方を見る', '解題想法')}</summary><div class="inner"><p id="idea"></p></div></details>
    </div>
    <details class="codecol" id="codecol"><summary>${t3('Solution code', '解答コード', '解答程式碼')}</summary>
      <div class="codehead"><span class="lbl mono">${esc(it.id)}.cpp</span><button type="button" class="btn" data-act="copy">${t3('Copy', 'コピー', '複製', 'compact')}</button></div>
      <pre class="src" id="code"></pre></details></div>`;
  fillProblem(it);
  if (hadFocus) { const b = main.querySelector(`.pager [data-act="${hadFocus}"]:not([disabled])`); if (b) b.focus(); }
}

function fillProblem(it) {
  const st = it.stmt;
  const sheet = $('#sheet');
  for (let i = 1; i <= it.pages; i++) {
    const img = document.createElement('img');
    img.src = `problems/${it.id}-${i}.png`; img.alt = `${it.id} ${it.title} (PDF page ${i})`; img.loading = i === 1 ? 'eager' : 'lazy';
    sheet.append(img);
  }
  if (st.note) { const n = $('#note'); n.textContent = st.note; n.hidden = false; }
  const vt = $('#vocab');
  st.vocab.forEach((v) => {
    const tr = vt.insertRow(); const a = tr.insertCell(), b = tr.insertCell();
    a.className = 'ven'; a.textContent = v.en; b.textContent = v.ja;
    if (v.note) { const s = document.createElement('div'); s.className = 'vnote'; s.textContent = v.note; b.append(s); }
  });
  // 単語リストの語を英文中で探して下線を引く（長い語を優先）
  const terms = st.vocab.map((v) => v.en).filter(Boolean).sort((a, b) => b.length - a.length);
  const meaning = Object.fromEntries(st.vocab.map((v) => [v.en.toLowerCase(), v.ja]));
  const re = terms.length ? new RegExp('(' + terms.map((t) => t.replace(/[.*+?^${}()|[\]\\]/g, '\\$&')).join('|') + ')', 'gi') : null;
  const fillEn = (el, text) => {
    if (!re) { el.textContent = text; return; }
    text.split(re).forEach((part, i) => {
      if (i % 2) { const s = document.createElement('span'); s.className = 'vw'; s.textContent = part; s.title = meaning[part.toLowerCase()] || ''; el.append(s); }
      else if (part) el.append(part);
    });
  };
  [['st', st.statement], ['in', st.input], ['out', st.output]].forEach(([id, paras]) => {
    const jb = $('#ja-' + id), eb = $('#en-' + id);
    paras.forEach(({ en, ja }) => {
      if (ja) { const p = document.createElement('p'); p.textContent = ja; jb.append(p); }
      if (en) { const p = document.createElement('p'); fillEn(p, en); eb.append(p); }
    });
  });
  $('#sin').textContent = it.sample.in; $('#sout').textContent = it.sample.out; $('#idea').textContent = it.idea;
  const pre = $('#code'); pre.textContent = '';
  it.code.split('\n').forEach((line, i) => {
    if (i) pre.append('\n');
    const at = line.indexOf('//');
    if (at < 0) { pre.append(line); return; }
    pre.append(line.slice(0, at));
    const s = document.createElement('span'); s.className = 'cm'; s.textContent = line.slice(at); pre.append(s);
  });
  document.querySelectorAll('#main details[data-k]').forEach((el) => { el.open = fold[el.dataset.k]; el.ontoggle = () => { fold[el.dataset.k] = el.open; }; });
  const cc = $('#codecol'); cc.open = wide.matches || codeOpen; cc.ontoggle = () => { if (!wide.matches) codeOpen = cc.open; };
}

/* ───────── PDF 一覧 ───────── */
function renderPdf() {
  const D = D_();
  const gs = D.cats.map((c) => ({ c, items: D.items.filter((x) => x.cat === c.id && matches(x, { q: S.q })).sort((a, b) => a.no.localeCompare(b.no)) })).filter((g) => g.items.length);
  const n = gs.reduce((a, g) => a + g.items.length, 0);
  $('#main').innerHTML = `
    <p class="eyebrow">${esc(D.label.en)}</p>
    <h2 style="font-size:1.6rem">${t3('PDF list', 'PDF一覧', 'PDF 列表')}</h2>
    <p class="lead">${t3('Open the original problem PDF, or read it here.', '元の問題PDFを開く、またはこのページで読みます。', '開啟原始題目 PDF，或在此頁閱讀。')}</p>
    <div class="bar"><div class="search"><label class="sr" for="q">Search</label><input id="q" type="search" autocomplete="off" placeholder="Title, UVa, ID / 題名・UVa・ID / 標題・UVa・ID" value="${esc(S.q)}"><kbd aria-hidden="true">/</kbd></div><span class="count" id="pcount">${n} / ${D.items.length}</span></div>
    <div id="pdfbody">${pdfBody(gs)}</div>`;
}
function pdfBody(gs) {
  if (!gs.length) return '<div class="empty">No matches. / 見つかりません。 / 找不到。</div>';
  return gs.map(({ c, items }) => `<h3 class="sec-title">${t3o(c)}<span class="gc">${items.length}</span></h3><div class="cards">${items.map((it) => `
    <article class="card" style="--pc:var(${TYPES[it.types[0]].color})"><div class="cid"><span>${it.id}</span><span>UVa ${it.uva}${solved[it.id] ? ' · ✓' : ''}</span></div>
      <div class="ct">${esc(it.title)}</div>
      <div class="cl"><a href="${encodeURI(it.pdf)}" target="_blank" rel="noopener">PDF ↗</a><a href="${hrefOf(S.set, 'problems', it.id)}">${t3('Read', '読む', '閱讀', 'compact')} →</a></div></article>`).join('')}</div>`).join('');
}

/* ───────── 考え方の型 ───────── */
function renderPatterns() {
  const D = D_(), ex = LOOP_EX[S.set];
  const chip = (n) => { const id = exId(S.set, n); return `<a href="${hrefOf(S.set, 'problems', id)}">${id}</a>`; };
  const loopRows = [
    ['until end of file / 個数が書いていない', 'while (cin &gt;&gt; x)', ex.eof],
    ['A line containing 0 ends the input', 'if (x == 0) break;', ex.zero],
    ['The first line contains the number of test cases', 'cin &gt;&gt; t; while (t--)', ex.t],
    ['line / sentence（空白を含む1行）', 'getline(cin, s)', ex.line],
  ];
  $('#main').innerHTML = `
    <p class="eyebrow">${esc(D.label.en)}</p>
    <h2 style="font-size:1.6rem">${t3('Patterns', '考え方の型', '解題模式')}</h2>
    <p class="lead">${D.items.length}問は、だいたい<b>8つの型</b>の組み合わせでできています。問題文を読んだら、まず5つの質問に答えて、どの型かを当てます。コードはそのあとです。</p>
    <h3 class="sec-title">${t3('Five questions before coding', '解く前の5つの質問', '解題前的五個問題')}</h3>
    <ol class="steps" style="margin-top:12px">
      <li><div><div class="q">入力はいつ終わる？</div><p>問題文の Input の書き方で、ループの形が決まります。</p>
        <table class="plain"><tr><th>問題文のサイン</th><th>ループの形</th><th>例</th></tr>${loopRows.map(([a, b, ns]) => `<tr><td>${a}</td><td class="mono">${b}</td><td>${ns.map(chip).join(', ')}</td></tr>`).join('')}</table></div></li>
      <li><div><div class="q">数はどれくらい大きい？</div><p>int は約21億（10桁）まで、long long は約900京（19桁）まで。それより大きい数は string で読みます。</p></div></li>
      <li><div><div class="q">何を答える問題？</div><p>「何個？」なら数える型、「順番に並べて」なら並べる型、「〜かどうか」なら判定です。答えの形を先に決めます。</p></div></li>
      <li><div><div class="q">全部試しても間に合う？</div><p>目安は <b>1秒でおよそ1億回（10<sup>8</sup>）</b>。範囲が小さければ全部試すのが一番安全で、間に合わないときだけ公式を探します。</p></div></li>
      <li><div><div class="q">出力の形は？</div><p>単数と複数（operation / operations）、空行がケースの「間」か「後」か、小数は何桁か、<code>Case 1:</code> の書き方。正しく解けていても、ここを間違えると不正解になります。</p></div></li>
    </ol>
    <h3 class="sec-title">${t3('Eight patterns', '8つの型', '八種模式')}</h3>
    <div class="pc-grid">${Object.entries(TYPES).map(([k, p]) => {
      const mine = D.items.filter((x) => x.types.includes(k)).sort((a, b) => a.no.localeCompare(b.no));
      return `<article class="pcard" style="--pc:var(${p.color})"><h3>${t3o(p.name)}</h3><div class="one">${esc(p.one)}</div>
        <div><div class="lbl">問題文のサイン</div>${esc(p.sig)}</div><div><div class="lbl">小さい例</div>${esc(p.ex)}</div>
        <div><div class="lbl">コードの形</div><code>${esc(p.code)}</code></div>
        <div><div class="lbl">この選集の問題（${mine.length}問）</div><div class="pchips">${mine.map((x) => `<button type="button" data-act="open" data-id="${x.id}" title="${esc(x.title)}">${x.no}</button>`).join('')}</div></div></article>`;
    }).join('')}</div>
    <h3 class="sec-title">${t3('Easy first', '簡単な順', '由易到難')}</h3>
    <p class="lead">上から順に解くと、前の問題で使った書き方が次の問題でそのまま使えます。</p>
    ${TIERS.map((t, i) => { const its = D.items.filter((x) => x.tier === i + 1).sort((a, b) => a.rank - b.rank); return its.length ? `<div class="tier"><div class="tier-h"><span class="lv">${t.lv}</span><h4>${t3(t.en, t.ja, t.zh, 'compact')}</h4><span class="eyebrow">${esc(t.why)}</span></div>
      <div class="grid">${its.map((x) => `<button type="button" class="cell${solved[x.id] ? ' solved' : ''}" data-act="open" data-id="${x.id}"><span class="no">${x.id}</span><span>${esc(x.title)}</span></button>`).join('')}</div></div>` : ''; }).join('')}`;
}

/* ───────── 操作 ───────── */
function move(dir) {
  if (S.tab !== 'problems') return;
  const fl = flat(groups(S));
  const idx = fl.findIndex((x) => x.id === S.id);
  const to = idx < 0 ? fl[0] : fl[idx + dir];
  if (to) go(S.set, 'problems', to.id);
  window.scrollTo({ top: 0 });
}
function toggleSolved(id, on) {
  const v = on === undefined ? !solved[id] : on;
  if (v) solved[id] = true; else delete solved[id];
  store.set('cpe:solved', solved);
  renderProgress();
  if (S.tab === 'problems') {
    renderList();
    const b = $('[data-act="solve"]');
    if (b) { b.setAttribute('aria-pressed', String(!!solved[id])); b.innerHTML = `${solved[id] ? '✓ ' : ''}${t3('Solved', '解いた', '已解', 'compact')}`; }
  }
}

document.addEventListener('click', (e) => {
  const el = e.target.closest('[data-act]');
  if (!el) return;
  const a = el.dataset.act;
  if (a === 'set') go(el.dataset.set, S.tab, null);
  else if (a === 'tab') go(S.set, el.dataset.tab, null);
  else if (a === 'pick') { go(S.set, 'problems', el.dataset.id); document.body.classList.remove('drawer-open'); window.scrollTo({ top: 0 }); }
  else if (a === 'open') { go(S.set, 'problems', el.dataset.id); window.scrollTo({ top: 0 }); }
  else if (a === 'prev') move(-1);
  else if (a === 'next') move(1);
  else if (a === 'solve') toggleSolved(el.dataset.id);
  else if (a === 'type') { S.type = S.type === el.dataset.type ? null : el.dataset.type; document.querySelectorAll('.chip').forEach((c) => c.setAttribute('aria-pressed', String(c.dataset.type === S.type))); renderList(); renderPagerOnly(); }
  else if (a === 'unsolved') { S.unsolved = !S.unsolved; el.setAttribute('aria-pressed', String(S.unsolved)); renderList(); renderPagerOnly(); }
  else if (a === 'clear') { S.q = ''; S.type = null; S.tier = 0; S.unsolved = false; renderSide(true); renderPagerOnly(); }
  else if (a === 'drawer') { const o = document.body.classList.toggle('drawer-open'); $('#drawer-btn').setAttribute('aria-expanded', String(o)); }
  else if (a === 'drawer-close') document.body.classList.remove('drawer-open');
  else if (a === 'copy') {
    const it = D_().items.find((i) => i.id === S.id);
    const done = () => { el.textContent = '✓'; setTimeout(() => { el.innerHTML = t3('Copy', 'コピー', '複製', 'compact'); }, 1400); };
    (navigator.clipboard ? navigator.clipboard.writeText(it.code) : Promise.reject()).then(done, () => {
      const r = document.createRange(); r.selectNodeContents($('#code')); const s = getSelection(); s.removeAllRanges(); s.addRange(r); el.textContent = '⌘C';
    });
  }
});
document.addEventListener('input', (e) => {
  if (e.target.id === 'q') {
    S.q = e.target.value;
    if (S.tab === 'pdf') { const D = D_(); const gs = D.cats.map((c) => ({ c, items: D.items.filter((x) => x.cat === c.id && matches(x, { q: S.q })).sort((a, b) => a.no.localeCompare(b.no)) })).filter((g) => g.items.length); $('#pdfbody').innerHTML = pdfBody(gs); $('#pcount').textContent = `${gs.reduce((n, g) => n + g.items.length, 0)} / ${D.items.length}`; }
    else { renderList(); renderPagerOnly(); }
  }
});
document.addEventListener('change', (e) => {
  const t = e.target;
  if (t.id === 'tier') { S.tier = +t.value; renderList(); renderPagerOnly(); }
  else if (t.id === 'order') { S.order = t.value; renderList(); renderPagerOnly(); }
  else if (t.id === 'jump') { go(S.set, 'problems', t.value); window.scrollTo({ top: 0 }); }
  else if (t.classList.contains('done')) toggleSolved(t.dataset.id, t.checked);
});
// フィルタが変わったとき、ページャー（位置・ジャンプ先・前後）だけを作り直す
function renderPagerOnly() {
  if (S.tab !== 'problems') return;
  const it = D_().items.find((i) => i.id === S.id);
  const fl = flat(groups(S));
  const idx = fl.findIndex((x) => x.id === it.id);
  const prev = idx > 0 ? fl[idx - 1] : null, next = idx >= 0 ? fl[idx + 1] : fl[0];
  const pager = $('.pager'); if (!pager) return;
  pager.querySelector('[data-act="prev"]').disabled = !prev;
  pager.querySelector('[data-act="next"]').disabled = !next;
  $('#pos').textContent = `${idx >= 0 ? idx + 1 : '–'} / ${fl.length}`;
  $('#jump').innerHTML = fl.map((x) => `<option value="${x.id}"${x.id === it.id ? ' selected' : ''}>${x.no} ${esc(x.title)}</option>`).join('') + (idx < 0 ? `<option value="${it.id}" selected>${it.no} ${esc(it.title)}</option>` : '');
  pager.querySelector('.hint').innerHTML = idx >= 0 && !next ? '<span class="end">Last problem / 最後の問題です</span>' : '← → / j k';
}
document.addEventListener('keydown', (e) => {
  if (e.key === 'Escape') { document.body.classList.remove('drawer-open'); return; }
  const tag = (e.target.tagName || '').toLowerCase();
  const typing = tag === 'input' || tag === 'textarea' || tag === 'select' || e.target.isContentEditable;
  if (typing || e.metaKey || e.ctrlKey || e.altKey) return;
  if (e.key === '/') { const q = $('#q'); if (q) { e.preventDefault(); if (innerWidth <= 960 && S.tab === 'problems') document.body.classList.add('drawer-open'); q.focus(); } }
  else if (e.key === 'ArrowRight' || e.key === 'j') move(1);
  else if (e.key === 'ArrowLeft' || e.key === 'k') move(-1);
});
wide.addEventListener('change', () => { const cc = $('#codecol'); if (cc) cc.open = wide.matches || codeOpen; });
window.addEventListener('hashchange', applyRoute);
applyRoute();
})();
