#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int> > &matrix) {

        int n = matrix.size();
        for (int layer=0; layer<n/2; layer++){
            int first = layer;
            int last  = n-1-layer; 
            for (int i=first;i<last;i++){
                int offset = i-first;
                int top = matrix[first][i];
                //left->top            
                matrix[first][i]=matrix[last-offset][first];
                //bottom->top
                matrix[last-offset][first] = matrix[last][last-offset];
                //right->bottom
                matrix[last][last-offset] = matrix[i][last];
                //top->right
                matrix[i][last] = top;
            }
        }
}

int mainrotate()
{

	system("pause");
	return 0;
}