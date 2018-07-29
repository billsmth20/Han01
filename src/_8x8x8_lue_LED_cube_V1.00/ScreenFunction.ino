int SCREEN_LENGTH = 28;
volatile int8_t screen[28][3] = {
  {0, 7}, {0, 6}, {0, 5}, {0, 4}, {0, 3}, {0, 2}, {0, 1},
  {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0},
  {7, 0}, {7, 1}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {7, 6},
  {7, 7}, {6, 7}, {5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7},
};
volatile int8_t content[] = {
  B11111111,
  B10111110,
  B00000000,
  B11111110,
  B11111111
};

int content_len;

void Screen01() {
  int yy, zz, suby, subz;
  int m, o, p = 0, q;
  content_len = sizeof(content) / sizeof(content[0]);
  for (int n = 0; n <= SCREEN_LENGTH + content_len; n++) {
    o = n;
    for (int i = 0; i < SCREEN_LENGTH + content_len; i++) {
      yy = screen[i][0];
      zz = screen[i][1];
      cube[yy][zz] = 0xFF;
    }

    if (o <= content_len) {
      p = 0;
      for (; o >= 0; o--) {
        yy = screen[o][0];
        zz = screen[o][1];
        cube[yy][zz] = content[p];
        p++;
      }
    } else if (o <= SCREEN_LENGTH) {
      q = o - content_len;
      p = 0;
      for (; o > q; o--) {
        yy = screen[o][0];
        zz = screen[o][1];
        cube[yy][zz] = content[p];
        p++;
      }
    } else {
      o = o - content_len;
      p = content_len - 1;
      for (; o < SCREEN_LENGTH; o++) {
        yy = screen[o][0];
        zz = screen[o][1];
        cube[yy][zz] = content[p];
        p--;
      }
    }
    delay(100);
  }
}
