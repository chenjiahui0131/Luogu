base_dir=problems/$1/
mkdir -p ${base_dir}
touch ${base_dir}description.md
touch ${base_dir}solution.md
touch ${base_dir}solution.cpp

cat >> ${base_dir}solution.cpp <<EOF
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}
EOF

cat >> ${base_dir}solution.md <<EOF
# 题解及思考
EOF