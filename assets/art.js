/* 1950年のドット（網点・ベンデイ・ドット）の部品: 表紙の絵・進捗メーター・「解いた」の印・ロゴ。
 * すべて自前の SVG / HTML で、外部画像は使わない。 */
window.Art = (() => {
  // 表紙の絵: 明るさ関数 v(x,y)∈[0,1] から、格子状に半径の違う円を並べて印刷の網点にする。
  // 太陽はマゼンタ、丘と波はシアン。黄色の紙の上に重ねる（multiply）ので、太陽は赤く見える。
  const hero = (total) => {
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
    const line = Array.from({ length: 31 }, (_, i) => `L${(i + 1) * 20} ${ridge((i + 1) * 20).toFixed(0)}`).join(' ');
    return `<svg class="b-art" viewBox="0 0 ${W} ${H}" preserveAspectRatio="xMidYMid slice" aria-hidden="true" focusable="false">
      <rect width="${W}" height="${H}" fill="var(--b-yellow)"/>
      <path d="M0 ${ridge(0).toFixed(0)} ${line} L${W} ${H} L0 ${H} Z" fill="var(--panel)"/>
      <g class="b-mag" fill="var(--b-mag)" style="mix-blend-mode:multiply">${mag}</g>
      <g fill="var(--b-cyan)">${cyn}</g>
      <g fill="none" stroke="var(--b-ink)" stroke-width="3.5" stroke-linejoin="round" stroke-linecap="round">
        <path d="M0 ${ridge(0).toFixed(0)} ${line}"/>
        <circle cx="430" cy="128" r="64"/>
      </g>
    </svg>
    <div class="b-bubble" aria-hidden="true">LEARN!</div><div class="b-pow" aria-hidden="true">${total} PROBLEMS</div>`;
  };

  // 進捗メーター: 20個のドットを、解いた割合だけ塗る
  const meter = (pct, done, total, size = 'lg') => {
    const n = 20, on = Math.round((pct / 100) * n);
    return `<div class="m-b ${size}" role="img" aria-label="${done} / ${total}">${Array.from({ length: n }, (_, i) => `<i${i < on ? ' class="on"' : ''}></i>`).join('')}</div>`;
  };

  // 「解いた」の印: 星形の SOLVED!（押したときだけ弾む）
  const badge = (cls = '') => `<svg class="badge-b ${cls}" viewBox="0 0 120 120" role="img" aria-label="Solved / 解いた / 已解"><polygon points="60,4 74,30 104,22 94,52 118,70 88,80 90,112 62,98 36,116 34,86 4,76 26,56 12,28 42,34" fill="var(--b-yellow)" stroke="var(--b-ink)" stroke-width="5" stroke-linejoin="round"/><text x="60" y="68" text-anchor="middle" font-family="Bangers, 'Dela Gothic One', sans-serif" font-size="24" fill="var(--b-mag)" stroke="var(--b-ink)" stroke-width="1.2">SOLVED!</text></svg>`;

  // ロゴの印
  const mark = () => '<svg class="mark-b" viewBox="0 0 40 40" aria-hidden="true"><circle cx="20" cy="20" r="18" fill="var(--b-yellow)" stroke="var(--b-ink)" stroke-width="3"/><g fill="var(--b-mag)"><circle cx="14" cy="14" r="3.2"/><circle cx="26" cy="14" r="2.2"/><circle cx="14" cy="26" r="2.2"/><circle cx="26" cy="26" r="3.2"/><circle cx="20" cy="20" r="2.6"/></g></svg>';

  return { hero, meter, badge, mark };
})();
