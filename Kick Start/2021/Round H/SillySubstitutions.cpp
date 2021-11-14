#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back

using namespace std;

struct Node {
  char val;
  Node* next;

  Node(): next(nullptr) {}
};

Node* swapNodes(Node* cur, Node* prev, char nv) {
  prev->next = cur->next;
  prev->val = nv;
  delete cur;
  return prev->next;
}

void findCounts(Node *cur, ll *counts) {
  Node *prev = nullptr;
  for(int i=0; i<10; i++) {
    counts[i]=0;
  }

  while(cur != nullptr) {
    if(prev != nullptr) {
      if(prev->val == '0' && cur->val == '1') {
        counts[0]++;
      } else if(prev->val == '1' && cur->val == '2') {
        counts[1]++;
      } else if(prev->val == '2' && cur->val == '3') {
        counts[2]++;
      } else if(prev->val == '3' && cur->val == '4') {
        counts[3]++;
      } else if(prev->val == '4' && cur->val == '5') {
        counts[4]++;
      } else if(prev->val == '5' && cur->val == '6') {
        counts[5]++;
      } else if(prev->val == '6' && cur->val == '7') {
        counts[6]++;
      } else if(prev->val == '7' && cur->val == '8') {
        counts[7]++;
      } else if(prev->val == '8' && cur->val == '9') {
        counts[8]++;
      } else if(prev->val == '9' && cur->val == '0') {
        counts[9]++;
      }
    }

    prev = cur;
    cur = cur->next;
  }
}

int main() {
  ll t;

  cin >> t;
  for(int _=0; _<t; _++) {
    ll n;
    string s;
    cin >> n;
    cin >> s;
    Node* root = nullptr;
    Node* cur = nullptr;
    Node* prev = nullptr;
    for(char c: s) {
      if(root == nullptr) {
        root = new Node();
        cur = root;
      } else {
        cur->next = new Node();
        cur = cur->next;
      }

      cur->val = c;
    }
    ll csize = n;
    ll psize = -1;
    ll counts[10];
    findCounts(root, counts);
    while(csize != psize) {
      psize = csize;
      bool fc = false;
      for(int i=1; i<=10; i++) {
        // if(fc) {
        //   findCounts(root, counts);
        //   fc = false;
        // }
        if(counts[i-1] > 0) {
          fc = true;
          cur = root;
          prev = nullptr;
          while(cur != nullptr) {
            if(prev != nullptr) {
              switch (i) {
                case 1:
                  if(cur->val == '1' && prev->val == '0') {
                    cur=swapNodes(cur, prev, '2');
                    csize--;

                    if(cur != nullptr && cur->next != nullptr) {
                      if(cur->next->val == '2') {
                        counts[1]--;
                      } else if(cur->next->val == '3') {
                        counts[2]++;
                      }
                    }
                  } else {
                    prev = cur;
                    cur = cur->next;
                  }
                  break;
                case 2:
                  if(cur->val == '2' && prev->val == '1') {
                    cur=swapNodes(cur, prev, '3');
                    csize--;
                    if(cur != nullptr && cur->next != nullptr) {
                      if(cur->next->val == '3') {
                        counts[2]--;
                      } else if(cur->next->val == '4') {
                        counts[3]++;
                      }
                    }
                  } else {
                    prev = cur;
                    cur = cur->next;
                  }
                  break;
                case 3:
                  if(cur->val == '3' && prev->val == '2') {
                    cur=swapNodes(cur, prev, '4');
                    csize--;
                    if(cur != nullptr && cur->next != nullptr) {
                      if(cur->next->val == '4') {
                        counts[3]--;
                      } else if(cur->next->val == '5') {
                        counts[4]++;
                      }
                    }
                  } else {
                    prev = cur;
                    cur = cur->next;
                  }
                  break;
                case 4:
                  if(cur->val == '4' && prev->val == '3') {
                    cur=swapNodes(cur, prev, '5');
                    csize--;
                    if(cur != nullptr && cur->next != nullptr) {
                      if(cur->next->val == '5') {
                        counts[4]--;
                      } else if(cur->next->val == '6') {
                        counts[5]++;
                      }
                    }
                  } else {
                    prev = cur;
                    cur = cur->next;
                  }
                  break;
                case 5:
                  if(cur->val == '5' && prev->val == '4') {
                    cur=swapNodes(cur, prev, '6');
                    csize--;
                    if(cur != nullptr && cur->next != nullptr) {
                      if(cur->next->val == '6') {
                        counts[5]--;
                      } else if(cur->next->val == '7') {
                        counts[6]++;
                      }
                    }
                  } else {
                    prev = cur;
                    cur = cur->next;
                  }
                  break;
                case 6:
                  if(cur->val == '6' && prev->val == '5') {
                    cur=swapNodes(cur, prev, '7');
                    csize--;
                    if(cur != nullptr && cur->next != nullptr) {
                      if(cur->next->val == '7') {
                        counts[6]--;
                      } else if(cur->next->val == '8') {
                        counts[7]++;
                      }
                    }
                  } else {
                    prev = cur;
                    cur = cur->next;
                  }
                  break;
                case 7:
                  if(cur->val == '7' && prev->val == '6') {
                    cur=swapNodes(cur, prev, '8');
                    csize--;
                    if(cur != nullptr && cur->next != nullptr) {
                      if(cur->next->val == '8') {
                        counts[7]--;
                      } else if(cur->next->val == '9') {
                        counts[8]++;
                      }
                    }
                  } else {
                    prev = cur;
                    cur = cur->next;
                  }
                  break;
                case 8:
                  if(cur->val == '8' && prev->val == '7') {
                    cur=swapNodes(cur, prev, '9');
                    csize--;
                    if(cur != nullptr && cur->next != nullptr) {
                      if(cur->next->val == '9') {
                        counts[8]--;
                      } else if(cur->next->val == '0') {
                        counts[9]++;
                      }
                    }
                  } else {
                    prev = cur;
                    cur = cur->next;
                  }
                  break;
                case 9:
                  if(cur->val == '9' && prev->val == '8') {
                    cur=swapNodes(cur, prev, '0');
                    csize--;
                    if(cur != nullptr && cur->next != nullptr) {
                      if(cur->next->val == '0') {
                        counts[9]--;
                      } else if(cur->next->val == '1') {
                        counts[0]++;
                      }
                    }
                  } else {
                    prev = cur;
                    cur = cur->next;
                  }
                  break;
                case 10:
                  if(cur->val == '0' && prev->val == '9') {
                    cur=swapNodes(cur, prev, '1');
                    csize--;
                    if(cur != nullptr && cur->next != nullptr) {
                      if(cur->next->val == '1') {
                        counts[0]--;
                      } else if(cur->next->val == '2') {
                        counts[1]++;
                      }
                    }
                  } else {
                    prev = cur;
                    cur = cur->next;
                  }
                  break;
                
                default:
                  break;
              }
            } else {
              prev = cur;
              cur = cur->next;
            }
          }
        }
      }
    }

    cout << "Case #" << _+1 << ": ";
    cur = root;
    while(cur != nullptr) {
      cout << cur->val;
      cur = cur->next;
    }
    cout << endl;
  }
}
