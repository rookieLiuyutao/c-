#include <cstdio>
#include <cctype>
const int N, M, End, tot_f;
char Card_Heap[2005];
struct Role {
    char tp, V[2015];
    int top, hp;
    bool atk, jp, lk;
    Role() {
        top = hp = 4;
    }
    inline void ReSet() {
        int tot = 0;

        for (int i = 1; i <= top; ++i)
            if (V[i]^'#')
                V[++tot] = V[i];

        top = tot;
    }
    inline void Get(int x) {
        if (End)
            return;

        while (x) {
            V[++top] = Card_Heap[M], --x;

            if (M > 1)
                --M;
        }
    }
    inline bool Find(char c) {
        for (int i = 1; i <= top; ++i)
            if (V[i] == c)
                return V[i] = '#', true;

        return false;
    }
    inline void Court() {
        if (!jp)
            lk = true;
    }
    inline void Show() {
        ReSet();

        if (hp <= 0) {
            puts("DEAD");
            return;
        }

        if (top) {
            for (int i = 1; i < top; ++i)
                putchar(V[i]), putchar(' ');

            printf("%c\n", V[top]);
        } else
            puts("");
    }
} A[15];
inline char GC() {
    char s[3];
    scanf("%s", s);
    return *s;
}
inline int Distance(int x, int y) {
    int d = 1;

    for (int i = (x + 1) % N; i ^ y; (++i) %= N)
        if (A[i].hp > 0)
            ++d;

    return d;
}
inline void Die(int o, int fr) {
    if (A[o].tp == 'M') {
        End = 2;
        return;
    }

    if (A[o].tp == 'F') {
        if (!--tot_f)
            End = 1;

        A[fr].Get(3);
    }

    if (A[o].tp == 'Z' && A[fr].tp == 'M')
        A[fr].top = 0, A[fr].atk = false;
}
inline void BeAtked(int o, int fr) {
    if (!--A[o].hp) {
        if (A[o].Find('P'))
            ++A[o].hp;
        else
            Die(o, fr);
    }
}
bool WX(int o, bool f) {
    for (int i = o;;) {
        if (A[i].hp)
            if ((f && A[i].tp == 'F') || (!f && A[i].tp^'F')) {
                if (A[i].Find('J'))
                    return A[i].jp = true, !WX(i, !f);
            }

        if (((++i) %= N) == o)
            return false;
    }
}
inline bool NWX(int o, int fr) {
    if (A[o].tp^'M' && !A[o].jp)
        return false;

    return WX(fr, A[o].tp == 'F');
}
int Duel(int k, int frm) {
    if (A[k].tp == 'Z' && A[frm].tp == 'M')
        return 1;

    if (NWX(k, frm))
        return 2; // (pre)return 0

    for (;;) {
        if (!A[k].Find('K'))
            return 1;

        if (!A[frm].Find('K'))
            return 0;
    }
}
inline bool K(int o, bool way) {
    if (A[o].tp == 'F') {
        if (Distance(o, 0) == 1 && way) {
            A[o].jp = true;

            if (!A[0].Find('D'))
                BeAtked(0, o);

            return true;
        }

        if (!way) {
            A[o].jp = true;
            int _ = Duel(0, o);

            if (_ == 1)
                BeAtked(0, o);
            else if (!_)
                BeAtked(o, 0);

            return true;
        }
    }

    if (A[o].tp == 'M') {
        for (int i = (o + 1) % N; i ^ o; (++i) %= N)
            if (A[i].hp > 0) {
                if ((A[i].jp && A[i].tp == 'F') || (!A[i].jp && A[i].lk)) {
                    if (Distance(o, i) == 1 && way) {
                        if (!A[i].Find('D'))
                            BeAtked(i, o);

                        return true;
                    }

                    if (!way) {
                        int _ = Duel(i, o);

                        if (_ == 1)
                            BeAtked(i, o);
                        else if (!_)
                            BeAtked(o, i);

                        return true;
                    }
                }
            }
    } else {
        for (int i = (o + 1) % N; i ^ o; (++i) %= N)
            if (A[i].hp > 0) {
                if (A[i].jp && ((A[o].tp == 'F') != (A[i].tp == 'F'))) {
                    if (Distance(o, i) == 1 && way) {
                        A[o].jp = true;

                        if (!A[i].Find('D'))
                            BeAtked(i, o);

                        return true;
                    }

                    if (!way) {
                        A[o].jp = true;
                        int _ = Duel(i, o);

                        if (_ == 1)
                            BeAtked(i, o);
                        else if (!_)
                            BeAtked(o, i);

                        return true;
                    }
                }
            }
    }

    return false;
}
inline void All(int o, bool way) {
    for (int i = (o + 1) % N; i ^ o; (++i) %= N)
        if (A[i].hp > 0) {
            if (NWX(i, o))
                continue;

            if (way) {
                if (!A[i].Find('K')) {
                    if (A[i].tp == 'M')
                        A[o].Court();

                    BeAtked(i, o);
                }
            } else {
                if (!A[i].Find('D')) {
                    if (A[i].tp == 'M')
                        A[o].Court();

                    BeAtked(i, o);
                }
            }

            if (End)
                break;
        }
}
int main() {
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; ++i) {
        A[i].tp = GC(), tot_f += A[i].tp == 'F';

        for (int j = 1; j < 5; ++j)
            A[i].V[j] = GC();
    }

    if (!tot_f)
        End = 1;

    for (int i = M; i; --i)
        Card_Heap[i] = GC();

    for (int i = 0; !End; (++i) %= N)
        if (A[i].hp) {
            A[i].ReSet(), A[i].Get(2);
            bool atked = false;

            for (int j = 1; j <= A[i].top; ++j) {
                if (End || A[i].hp <= 0)
                    break;

                char &Cid = A[i].V[j];

                if (Cid == '#')
                    continue;

                if (Cid == 'P') {
                    if (A[i].hp < 4)
                        ++A[i].hp, Cid = '#';
                } else if (Cid == 'K') {
                    if (atked && !A[i].atk)
                        continue;

                    if (K(i, true))
                        atked = true, Cid = '#', j = 0;
                } else if (Cid == 'F') {
                    if (K(i, false))
                        Cid = '#', j = 0;
                } else if (Cid == 'Z') {
                    Cid = '#';

                    if (!A[i].atk)
                        A[i].atk = true, j = 0;
                } else if (Cid == 'N')
                    All(i, true), Cid = '#', j = 0;
                else if (Cid == 'W')
                    All(i, false), Cid = '#', j = 0;
            }
        }

    puts(End == 1 ? "MP" : "FP");

    for (int i = 0; i < N; ++i)
        A[i].Show();

    return 0;
}