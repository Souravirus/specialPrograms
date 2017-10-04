//codechef - card shuffle - https://www.codechef.com/problems/CARDSHUF/

#include <bits/stdc++.h>
using namespace std;

typedef int lli;

typedef struct treap {
	lli val, yi, ans, lazy; //ans its some function mats, etc.
  int size, reversed;
	treap *izq, *der;

	treap(lli VAL, lli YI = rand(), treap* I = NULL, treap* D = NULL) : 
	val(VAL), yi(YI), izq(I), der(D), size(1), ans(VAL), lazy(0), reversed(0) {}

	~treap() {
		free(izq);
		free(der);
	}
	
} treap;

typedef treap* ptreap; 

int SizeOf (ptreap t) { return (t) ? t->size : 0; }

void Recalc(ptreap t) { if(t) t->size = SizeOf(t->izq) + SizeOf(t->der) + 1; }

void Push(ptreap t) { 
  if (!t) return; //lazy can vary
  if (t->lazy) {
    t->val += t->lazy;
    t->ans += t->lazy; //as the maximum stays just add lazy value; sum of range would involve multiply the size of the tree
    if (t->izq) t->izq->lazy += t->lazy;
    if (t->der) t->der->lazy += t->lazy;
    t->lazy = 0;
  }
  if (t->reversed) {
    ptreap temp = t->izq;
    t->izq = t->der;
    t->der = temp;
    t->reversed = 0;
    if (t->izq) t->izq->reversed ^= 1;
    if (t->der) t->der->reversed ^= 1;
  }
}

void reset(ptreap t) { if (t) t->ans = t->val; } //as if the current node were new

void combine(ptreap& t, ptreap I, ptreap D) {
  if (!I || !D) { t->ans = I ? I->ans: D->ans; return; }
  t->ans = max(I->ans, D->ans); //combine function like SegTree
}

void operation(ptreap t) {
  if (!t) return;
  reset(t);
  Push(t->izq); Push(t->der);
  combine(t, t->izq, t);
  combine(t, t, t->der);
}

void Merge(ptreap &R, ptreap I, ptreap D) {
	Push(I); Push(D);
  if ((!I) && (!D)) { R = NULL; return; }
	if (I == NULL) { R = D; return; }
	if (D == NULL) { R = I; return; }
	if ((I->yi) > (D->yi)) { Merge(I->der, I->der, D); R = I;
	} else { Merge(D->izq, I, D->izq); R = D; }
	Recalc(R);
  operation(R);
}

void Split(ptreap R, ptreap &I, ptreap &D, int pos, int add = 0) {
	if (!R) { I = NULL; D = NULL; return; }
	Push(R);
  int curr_pos = add + SizeOf(R->izq) + 1;
  if (curr_pos <= pos) { Split(R->der, R->der, D, pos, curr_pos); I = R;
	} else { Split(R->izq, I, R->izq, pos, add); D = R; }
	Recalc(R);
  operation(R);
}

void Insert(ptreap &R, ptreap item, int pos) {
	ptreap i = NULL, d = NULL;
  Split(R, i, d, pos - 1);
  Merge(i, i, item);
  Merge(R, i, d);
}

void Remove(ptreap &R, int pos) {
	ptreap i, m, d;
  Split(R, i, m, pos - 1);
  Split(m, m, d, pos);
  Merge(R, i, d);
}

lli RangeQ(ptreap& R, int l, int r) {
  ptreap i = NULL, m = NULL, d = NULL;
  Split(R, i, m, l - 1);
  Split(m, m, d, r - l + 1); 
  lli res = m->ans;
  Merge(m, m, d);
  Merge(R, i, m);
  return res;
}

void RangeU(ptreap& R, int l, int r, lli val) {
  ptreap i = NULL, m = NULL, d = NULL;
  Split(R, i, m, l - 1);
  Split(m, m, d, r - l + 1);
  m->lazy += val;
  Merge(m, m, d);
  Merge(R, i, m);
}

void Reverse(ptreap& R, int l, int r) {
  ptreap i = NULL, m = NULL, d = NULL;
  Split(R, i, m, l - 1);
  Split(m, m, d, r - l + 1);
  m->reversed ^= 1;
  Merge(m, m, d);
  Merge(R, i, m);
}

void Process(ptreap& R, int Ai, int Bi, int Ci) {
  ptreap TopA, Rest;
  Split(R, TopA, Rest, Ai);
  ptreap NxtB;
  Split(Rest, NxtB, Rest, Bi);
  Merge(Rest, TopA, Rest);
  ptreap NxtC;
  Split(Rest, NxtC, Rest, Ci);
  NxtB->reversed = 1;
  Merge(Rest, NxtB, Rest);
  Merge(R, NxtC, Rest);
}

int main(){
  cin.tie(0); ios_base::sync_with_stdio(0);

  int N, Q;
  cin >> N >> Q;
  ptreap myTreap = NULL;

  for (int i = 1; i <= N; ++i) Insert(myTreap, new treap(i), i);

  for (int i = 1; i <= Q; ++i) {
    int Ai, Bi, Ci;
    cin >> Ai >> Bi >> Ci;
    Process(myTreap, Ai, Bi, Ci);
  }

  for (int i = 1; i <= N; ++i) {
    if (i > 1) cout << ' ';
    cout << RangeQ(myTreap, i, i);
  }
  cout << '\n';
  return 0;
}
