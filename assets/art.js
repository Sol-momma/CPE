/* スキンごとの絵と部品。
 * a = Google × Vogue（巨大な数字の紙面）/ b = 1950年のドット（網点）/ c = ファミコン（ドット絵）
 * すべて自前の SVG / HTML。外部画像は使わない。 */
window.Art = (() => {
  /* ───────── A: Google × Vogue ───────── */
  const typoHero = (total) => `<div class="a-hero" aria-hidden="true">
    <span class="a-num" style="--to:${total}"></span>
    <span class="a-cap">problems, one at a time.</span>
    <span class="a-cap2">問題 / 題目</span>
    <i class="a-line"></i>
  </div>`;

  /* ───────── B: 網点（ハーフトーン） ───────── */
  // 明るさ関数 v(x,y)∈[0,1] から、格子状に半径の違う円を並べて「印刷の網点」にする。
  const halftoneHero = () => {
    const W = 600, H = 400, step = 11;
    const smooth = (a, b, x) => { const t = Math.max(0, Math.min(1, (x - a) / (b - a))); return t * t * (3 - 2 * t); };
    const sun = (x, y) => 1 - smooth(40, 92, Math.hypot(x - 430, y - 128));
    const ridge = (x) => 230 + 34 * Math.sin(x / 70) + 22 * Math.sin(x / 31 + 1.3) - 60 * Math.exp(-Math.pow((x - 200) / 90, 2));
    const hills = (x, y) => { const r = ridge(x); return y > r ? 0.32 + 0.68 * smooth(r, H, y) : 0; };
    const wave = (x, y) => (y > 300 ? 0.18 + 0.12 * Math.sin(x / 14 + y / 9) : 0);
    let mag = '', cyn = '';
    for (let y = step / 2; y < H; y += step) {
      for (let x = step / 2; x < W; x += step) {
        const vs = sun(x, y), vh = Math.max(hills(x, y), wave(x, y));
        if (vs > 0.04) mag += `<circle cx="${(x + 2).toFixed(1)}" cy="${(y + 2).toFixed(1)}" r="${(step * 0.52 * Math.sqrt(vs)).toFixed(2)}"/>`;
        if (vh > 0.04) cyn += `<circle cx="${x.toFixed(1)}" cy="${y.toFixed(1)}" r="${(step * 0.52 * Math.sqrt(vh)).toFixed(2)}"/>`;
      }
    }
    return `<svg class="b-art" viewBox="0 0 ${W} ${H}" preserveAspectRatio="xMidYMid slice" aria-hidden="true" focusable="false">
      <rect width="${W}" height="${H}" fill="var(--b-yellow)"/>
      <g class="b-mag" fill="var(--b-mag)" style="mix-blend-mode:multiply">${mag}</g>
      <g class="b-cyn" fill="var(--b-cyan)" style="mix-blend-mode:multiply">${cyn}</g>
      <g fill="none" stroke="var(--b-ink)" stroke-width="3.5" stroke-linejoin="round" stroke-linecap="round">
        <path d="M0 ${ridge(0).toFixed(0)} ${Array.from({ length: 31 }, (_, i) => `L${(i + 1) * 20} ${ridge((i + 1) * 20).toFixed(0)}`).join(' ')}"/>
        <circle cx="430" cy="128" r="64"/>
      </g>
    </svg>
    <div class="b-bubble" aria-hidden="true">LEARN!</div><div class="b-pow" aria-hidden="true">105 PROBLEMS</div>`;
  };

  /* ───────── C: ドット絵 ───────── */
  const PAL = { '0': '#fff1e8', '1': '#83769c', 'r': '#ff004d', 'y': '#ffec27', 'g': '#00e436', 'G': '#008751', 'b': '#29adff', 'B': '#1d2b53', 'k': '#000', 'w': '#c2c3c7', 'o': '#ffa300' };
  const px = (rows, ox, oy, u = 8) => rows.flatMap((row, j) => [...row].map((ch, i) => (PAL[ch] ? `<rect x="${(ox + i) * u}" y="${(oy + j) * u}" width="${u}" height="${u}" fill="${PAL[ch]}"/>` : ''))).join('');
  const CLOUD = ['....0000....', '..00000000..', '.0000000000.', '000000000000', '.0000000000.'];
  const STAR = ['..y..', '.yyy.', 'yyyyy', '.yyy.', '.y.y.'];
  const COIN = ['.yy.', 'yooy', 'yooy', '.yy.'];
  const CASTLE = [
    'w.w.w.w.w.w.w.',
    'wwwwwwwwwwwwww',
    'w1w1wwww1w1www',
    'wwwwwwwwwwwwww',
    'wwwwwkkkkwwwww',
    'w1wwwkkkkww1ww',
    'wwwwwkkkkwwwww',
    'wwwwwkkkkwwwww',
  ];
  const pixelHero = () => {
    const u = 8, W = 64, H = 40; // 512 x 320
    const hill = (x) => 27 - Math.round(3 + 3 * Math.sin(x / 6) + 2 * Math.sin(x / 2.6));
    let ground = '', hills = '';
    for (let x = 0; x < W; x++) {
      const h = hill(x);
      hills += `<rect x="${x * u}" y="${h * u}" width="${u}" height="${(32 - h) * u}" fill="${PAL.G}"/><rect x="${x * u}" y="${h * u}" width="${u}" height="${u}" fill="${PAL.g}"/>`;
    }
    for (let x = 0; x < W; x += 2) ground += `<rect x="${x * u}" y="${32 * u}" width="${2 * u}" height="${8 * u}" fill="${(x / 2) % 2 ? '#ab5236' : '#7e2553'}"/><rect x="${x * u}" y="${32 * u}" width="${2 * u}" height="${u}" fill="${PAL.g}"/>`;
    return `<svg class="c-art" viewBox="0 0 ${W * u} ${H * u}" preserveAspectRatio="xMidYMax slice" shape-rendering="crispEdges" aria-hidden="true" focusable="false">
      <rect width="${W * u}" height="${H * u}" fill="${PAL.B}"/><rect y="${14 * u}" width="${W * u}" height="${12 * u}" fill="#1d2b53" opacity=".0"/>
      <g class="c-stars">${px(STAR, 6, 4)}${px(STAR, 24, 9)}${px(STAR, 52, 3)}</g>
      <g class="c-cloud c1">${px(CLOUD, 4, 12)}</g><g class="c-cloud c2">${px(CLOUD, 36, 7)}</g>
      ${hills}${ground}
      <g>${px(CASTLE, 46, 17)}</g>
      <g class="c-coin">${px(COIN, 14, 20)}</g><g class="c-coin d2">${px(COIN, 18, 17)}</g><g class="c-coin d3">${px(COIN, 22, 20)}</g>
    </svg>`;
  };

  /* ───────── 進捗メーター ───────── */
  // pct: 0〜100, done/total: 数, size: 'lg' | 'sm'
  const meter = (skin, pct, done, total, size = 'lg') => {
    if (skin === 'a') return `<div class="m-a ${size}"><b>${done}</b><span>/ ${total}</span><i style="--p:${pct}%"></i></div>`;
    if (skin === 'b') { const n = 20, on = Math.round((pct / 100) * n); return `<div class="m-b ${size}" role="img" aria-label="${done} / ${total}">${Array.from({ length: n }, (_, i) => `<i${i < on ? ' class="on"' : ''}></i>`).join('')}</div>`; }
    if (skin === 'c') { const n = 10, on = Math.round((pct / 100) * n); return `<div class="m-c ${size}" role="img" aria-label="${done} / ${total}"><span>HP</span>${Array.from({ length: n }, (_, i) => `<i${i < on ? ' class="on"' : ''}></i>`).join('')}</div>`; }
    return '';
  };

  /* ───────── 「解いた」の印 ───────── */
  const badge = (skin, cls = '') => {
    if (skin === 'a') return `<span class="badge-a ${cls}" role="img" aria-label="Solved / 解いた / 已解">Solved</span>`;
    if (skin === 'b') return `<svg class="badge-b ${cls}" viewBox="0 0 120 120" role="img" aria-label="Solved / 解いた / 已解"><polygon points="60,4 74,30 104,22 94,52 118,70 88,80 90,112 62,98 36,116 34,86 4,76 26,56 12,28 42,34" fill="var(--b-yellow)" stroke="var(--b-ink)" stroke-width="5" stroke-linejoin="round"/><text x="60" y="68" text-anchor="middle" font-family="Bangers, 'Dela Gothic One', sans-serif" font-size="24" fill="var(--b-mag)" stroke="var(--b-ink)" stroke-width="1.2">SOLVED!</text></svg>`;
    if (skin === 'c') return `<span class="badge-c ${cls}" role="img" aria-label="Solved / 解いた / 已解"><svg viewBox="0 0 40 40" shape-rendering="crispEdges">${px(STAR, 0, 0, 8)}</svg><b>CLEAR!</b></span>`;
    return '';
  };

  /* ───────── ロゴの印 ───────── */
  const mark = (skin) => {
    if (skin === 'a') return '<span class="mark-a" aria-hidden="true">C</span>';
    if (skin === 'b') return '<svg class="mark-b" viewBox="0 0 40 40" aria-hidden="true"><circle cx="20" cy="20" r="18" fill="var(--b-yellow)" stroke="var(--b-ink)" stroke-width="3"/><g fill="var(--b-mag)"><circle cx="14" cy="14" r="3.2"/><circle cx="26" cy="14" r="2.2"/><circle cx="14" cy="26" r="2.2"/><circle cx="26" cy="26" r="3.2"/><circle cx="20" cy="20" r="2.6"/></g></svg>';
    if (skin === 'c') return `<svg class="mark-c" viewBox="0 0 40 40" shape-rendering="crispEdges" aria-hidden="true"><rect width="40" height="40" fill="${PAL.r}"/>${px(['.0000.', '00..00', '00....', '00....', '00..00', '.0000.'], 0.5, 0.2, 6)}</svg>`;
    return '';
  };

  return { typoHero, halftoneHero, pixelHero, meter, badge, mark };
})();
