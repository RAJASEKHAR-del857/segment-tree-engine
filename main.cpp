
#include "segment_tree.h"

int main() {
    int n = 5;
    vector<int> arr = {1,2,3,4,5};

    SegmentTree st(arr);

    cout << "Initial Sum(1,3): " << st.query(0,0,n-1,1,3) << endl;

    st.updateRange(0,0,n-1,1,3,2);
    cout << "After Update Sum(1,3): " << st.query(0,0,n-1,1,3) << endl;

    return 0;
}
