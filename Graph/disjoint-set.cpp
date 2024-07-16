// Time  : O(4*alpha) ~ O(1)
// Space : O(V)
class DS {
public:
  vector<int> rank, parent;
  DS (int n) {
    rank.resize(n);
    parent.resize(n);
    for (int i=1; i<n; ++i) parent[i] = i;
  }
  int findPar(int x) {
    if (x==parent[x]) return x;
    return parent[x] = findPar(parent[x]);
  }
  void unionByRank(int u, int v) {
    int pu = findPar(u);
    int pv = findPar(v);
    if (pu==pv) return;
    if (rank[pu]<rank[pv]) parent[pu] = pv;
    else if (rank[pu]>rank[pv]) parent[pv] = pu;
    else { parent[pu] = pv; rank[pv]++; }
  }
};
class DS {
public:
  vector<int> size, parent;
  DS (int n) {
    size.resize(n,1);
    parent.resize(n);
    for (int i=1; i<n; ++i) parent[i] = i;
  }
  int findPar(int x) {
    if (x==parent[x]) return x;
    return parent[x] = findPar(parent[x]);
  }
  void unionBySize(int u, int v) {
    int pu = findPar(u);
    int pv = findPar(v);
    if (pu==pv) return;
    if (size[pu]<size[pv]) {
      parent[pu] = pv;
      size[pv] += size[pu];
    }
    else {
      parent[pv] = pu;
      size[pu] += size[pv];
    }
  }
};