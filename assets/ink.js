/* 水墨の部品: 山水画（表紙）・円相（進捗）・落款（解いた）。すべて手描きの SVG で、外部画像は使わない。 */
window.Ink = (() => {
  // 山水画: 遠山 → 霧 → 中景の奇峰 → 霧 → 水面と舟 → 近景の岩と松 → 渡り鳥。色は CSS 変数でテーマに追従する。
  const landscape = () => `
<svg class="hero-art" viewBox="0 0 1200 560" preserveAspectRatio="xMidYMax slice" aria-hidden="true" focusable="false">
  <defs>
    <linearGradient id="g-sky" x1="0" y1="0" x2="0" y2="1"><stop offset="0" stop-color="var(--sky-top)"/><stop offset="1" stop-color="var(--sky)"/></linearGradient>
    <linearGradient id="g-mist" x1="0" y1="0" x2="1" y2="0"><stop offset="0" stop-color="var(--mist)" stop-opacity="0"/><stop offset=".3" stop-color="var(--mist)"/><stop offset=".7" stop-color="var(--mist)"/><stop offset="1" stop-color="var(--mist)" stop-opacity="0"/></linearGradient>
    <linearGradient id="g-water" x1="0" y1="0" x2="0" y2="1"><stop offset="0" stop-color="var(--mist)" stop-opacity=".55"/><stop offset="1" stop-color="var(--mist)" stop-opacity="0"/></linearGradient>
  </defs>
  <rect class="sky" width="1200" height="560" fill="url(#g-sky)"/>
  <circle class="sun" cx="868" cy="168" r="58" fill="var(--sun)"/>

  <g class="layer l-far" style="--i:1"><g filter="url(#f-wash)" fill="var(--far)">
    <path d="M0 400 L0 322 C50 300 84 262 138 268 C196 274 218 214 288 180 C334 158 358 196 398 222 C440 250 486 232 528 262 C580 300 612 352 664 326 C722 296 756 232 818 214 C872 200 902 246 952 280 C1008 318 1056 296 1106 256 C1150 224 1180 246 1200 262 L1200 400 Z"/>
    <path d="M300 400 C330 350 372 330 410 338 C452 348 470 320 506 330 C560 346 584 392 600 400 Z" opacity=".7"/>
  </g></g>

  <g class="layer mist m1" style="--i:2"><g filter="url(#f-soft)">
    <ellipse cx="300" cy="352" rx="360" ry="26" fill="url(#g-mist)"/>
    <ellipse cx="900" cy="338" rx="380" ry="22" fill="url(#g-mist)"/>
  </g></g>

  <g class="layer l-mid" style="--i:3"><g filter="url(#f-rough)" fill="var(--mid)">
    <path d="M212 452 C214 372 228 296 250 224 C258 196 268 168 280 168 C292 168 296 198 306 232 C326 302 340 372 346 452 Z"/>
    <path d="M436 452 C440 392 450 336 470 290 C478 272 486 262 494 276 C512 312 524 380 528 452 Z" opacity=".86"/>
    <path d="M560 452 C562 402 574 348 590 312 C598 296 606 296 612 312 C626 350 634 404 636 452 Z" opacity=".7"/>
    <path d="M944 452 C948 382 962 316 984 262 C992 244 1002 244 1010 262 C1030 312 1044 382 1048 452 Z" opacity=".9"/>
    <path d="M1060 452 C1066 404 1082 360 1100 336 C1108 326 1116 328 1122 340 C1136 372 1142 414 1144 452 Z" opacity=".74"/>
  </g>
  <g class="strokes" stroke="var(--near)" stroke-width="1.6" stroke-linecap="round" fill="none" opacity=".16">
    <path d="M262 250 C264 300 268 350 274 420"/><path d="M280 214 C282 280 288 350 294 430"/><path d="M984 290 C986 340 990 390 996 430"/><path d="M480 316 C482 356 486 396 490 436"/>
  </g></g>

  <g class="layer mist m2" style="--i:4"><g filter="url(#f-soft)">
    <ellipse cx="520" cy="416" rx="440" ry="30" fill="url(#g-mist)"/>
    <ellipse cx="1000" cy="428" rx="320" ry="24" fill="url(#g-mist)"/>
  </g></g>

  <g class="layer l-water" style="--i:5">
    <rect x="0" y="446" width="1200" height="120" fill="url(#g-water)"/>
    <g stroke="var(--near)" stroke-linecap="round" fill="none" opacity=".22">
      <path d="M120 468 H300" stroke-width="1.4"/><path d="M420 482 H640" stroke-width="1.2"/><path d="M760 470 H980" stroke-width="1.4"/><path d="M200 506 H420" stroke-width="1"/><path d="M620 516 H900" stroke-width="1"/><path d="M980 500 H1150" stroke-width="1.2"/>
    </g>
    <g transform="translate(690 446)"><g class="boat">
      <path d="M0 14 C26 22 78 22 108 12 L100 6 C74 12 34 12 8 6 Z" fill="var(--near)" opacity=".9"/>
      <path d="M52 8 C52 -6 56 -18 60 -22" stroke="var(--near)" stroke-width="2" fill="none"/>
      <circle cx="52" cy="-26" r="4.4" fill="var(--near)"/>
      <path d="M40 -32 C46 -36 58 -36 64 -32 C58 -30 46 -30 40 -32 Z" fill="var(--near)"/>
      <path d="M84 -34 L84 10" stroke="var(--near)" stroke-width="1.2" opacity=".6"/>
    </g></g>
  </g>

  <g class="layer l-near" style="--i:6"><g filter="url(#f-rough)" fill="var(--near)">
    <path d="M0 560 L0 276 C36 268 66 230 108 232 C150 234 164 284 190 318 C212 346 232 390 238 560 Z"/>
    <path d="M1200 560 L1200 372 C1170 366 1148 392 1124 416 C1100 440 1092 500 1096 560 Z" opacity=".92"/>
  </g>
  <g fill="none" stroke="var(--near)" stroke-linecap="round">
    <path d="M118 238 C130 200 118 160 96 126 C84 106 92 84 112 70" stroke-width="7"/>
    <path d="M104 150 C128 142 156 150 176 138" stroke-width="3.6"/><path d="M110 118 C84 112 62 118 44 104" stroke-width="3.2"/>
  </g>
  <g stroke="var(--mid)" stroke-width="1.7" stroke-linecap="round" fill="none" opacity=".3">
    <path d="M26 300 C40 360 48 430 52 540"/><path d="M76 262 C88 330 96 410 100 540"/><path d="M134 304 C146 362 152 440 156 540"/><path d="M190 340 C200 392 206 456 208 540"/>
    <path d="M1118 430 C1112 470 1110 510 1112 548"/><path d="M1150 388 C1144 440 1142 500 1144 548"/>
  </g>
  <g fill="none" stroke="var(--near)" stroke-linecap="round" opacity=".92">
    <path d="M1150 392 C1146 368 1158 346 1176 328" stroke-width="5"/><path d="M1158 352 C1176 346 1192 350 1200 342" stroke-width="2.8"/><path d="M1166 334 C1150 330 1136 332 1126 322" stroke-width="2.6"/>
  </g>
  <g fill="var(--near)" filter="url(#f-rough)" opacity=".9"><ellipse cx="1182" cy="326" rx="26" ry="7"/><ellipse cx="1128" cy="320" rx="22" ry="6"/><ellipse cx="1196" cy="342" rx="18" ry="5"/></g>
  <g fill="var(--near)" filter="url(#f-rough)" opacity=".92">
    <ellipse cx="190" cy="136" rx="34" ry="9"/><ellipse cx="134" cy="150" rx="28" ry="7"/><ellipse cx="44" cy="100" rx="30" ry="8"/><ellipse cx="116" cy="70" rx="30" ry="8"/><ellipse cx="92" cy="104" rx="22" ry="6"/>
  </g></g>

  <g class="layer birds" style="--i:7" fill="none" stroke="var(--near)" stroke-width="2" stroke-linecap="round">
    <path d="M0 0 q9 -9 18 0 q9 -9 18 0" transform="translate(380 96)"/>
    <path d="M0 0 q7 -7 14 0 q7 -7 14 0" transform="translate(432 118)" opacity=".75"/>
    <path d="M0 0 q6 -6 12 0 q6 -6 12 0" transform="translate(344 130)" opacity=".6"/>
  </g>
  <rect class="grain" width="1200" height="560" filter="url(#f-grain)" opacity=".16"/>
</svg>`;

  // 円相: 進捗 pct(0〜100) に応じて筆の弧が伸びる。size は px。
  const enso = (pct, size = 40, label = '', animate = false) => {
    const p = Math.max(0, Math.min(100, pct));
    return `<svg class="enso${animate ? ' draw' : ''}" viewBox="0 0 100 100" width="${size}" height="${size}" role="img" aria-label="${label}" style="--p:${p}">
      <circle cx="50" cy="50" r="38" fill="none" stroke="var(--line)" stroke-width="5"/>
      <g filter="url(#f-brush)"><circle class="arc" cx="50" cy="50" r="38" fill="none" stroke="var(--ink)" stroke-width="8" stroke-linecap="round" pathLength="100" transform="rotate(-96 50 50)"/></g>
    </svg>`;
  };

  // 落款: 「済」の朱印。押したときだけ動く（.stamp-in）。
  const hanko = (cls = '') => `<svg class="hanko ${cls}" viewBox="0 0 64 64" role="img" aria-label="Solved / 解いた / 已解">
      <g filter="url(#f-brush)"><rect x="6" y="6" width="52" height="52" rx="7" fill="var(--seal)"/>
      <rect x="11" y="11" width="42" height="42" rx="3" fill="none" stroke="var(--seal-ink)" stroke-width="1.6" opacity=".7"/>
      <text x="32" y="46" text-anchor="middle" font-family="'Shippori Mincho B1','Noto Serif TC',serif" font-weight="800" font-size="34" fill="var(--seal-ink)">済</text></g></svg>`;

  // 題字の落款（「學」）
  const seal = () => `<svg class="seal" viewBox="0 0 64 64" aria-hidden="true"><g filter="url(#f-brush)"><rect x="5" y="5" width="54" height="54" rx="6" fill="var(--seal)"/>
      <text x="32" y="47" text-anchor="middle" font-family="'Shippori Mincho B1','Noto Serif TC',serif" font-weight="800" font-size="38" fill="var(--seal-ink)">學</text></g></svg>`;

  // ───── スキン（見た目）の切り替え: sumi（墨）/ a / b / c。部品は skin に応じて差し替える。
  const skin = () => document.documentElement.dataset.skin || 'sumi';
  const hero = (total) => {
    const k = skin();
    if (k === 'a') return Art.typoHero(total);
    if (k === 'b') return Art.halftoneHero();
    if (k === 'c') return Art.pixelHero();
    return `${landscape()}<div class="poem">學而時習之<br>不亦說乎<small>論語</small></div>${seal()}`;
  };
  const meter = (pct, size, done, total, animate, label = '') => {
    const k = skin();
    if (k === 'sumi') return enso(pct, size === 'sm' ? 30 : 84, label, animate);
    return Art.meter(k, pct, done, total, size);
  };
  const badge = (cls = '') => (skin() === 'sumi' ? hanko(cls) : Art.badge(skin(), cls));
  const mark = () => (skin() === 'sumi' ? seal() : Art.mark(skin()));
  return { landscape, enso, hanko, seal, skin, hero, meter, badge, mark };
})();
