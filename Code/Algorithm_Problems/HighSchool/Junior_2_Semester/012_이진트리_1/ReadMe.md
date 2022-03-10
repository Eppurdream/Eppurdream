```
    1. 이진 트리 순회
    - n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다. 이와 같은 이진 트리의 전위 순화와
    후위순회가 주어졌을 때, 중위순회를 구하는 프로그램을 작성하시오.
    - 입력은 첫째 줄에 n이 주어진다. 다음 줄에는 전위 순회를 나타내는 n개의 자연수가 주어지고, 그 다음 줄에는 같은 식으로
    후위순회가 주어진다.
```

- 풀이 코드

```cpp
    #include <iostream>
    #include <vector>
    #include <stack>
    using namespace std;

    vector<int> postorder;
    vector<int> makeInorder(vector<int> subTree);

    int main()
    {
        int n;
        cout << "몇개의 노드를 입력 받으실 건가요? : ";
        cin >> n;

        vector<int> preorder;

        int num = 0;
        cout << "전위 순회 입력" << endl; 
        for (int i = 0; i < n; i++)		// 하나 씩 입력 하는 코드 (전위)
        {
            cin >> num;
            preorder.push_back(num);
        }

        cout << "후위 순회 입력" << endl;
        for (int i = 0; i < n; i++)		// 하나 씩 입력 하는 코드 (후위)
        {
            cin >> num;
            postorder.push_back(num);
        }

        vector<int> inorder;

        inorder = makeInorder(preorder);

        cout << endl << endl << "중위 순회 : ";
        for (int i = 0; i < inorder.size(); i++)
        {
            cout << inorder[i] << " ";
        }

        return 0;
    };

    vector<int> makeInorder(vector<int> subTree)
    {
        int rootNode = subTree[0];
        vector<int> leftSubTree;
        vector<int> rightSubTree;
        
        // 예외처리 코드 1
        if (postorder[0] == rootNode)
        {
            cout << "잘못된 전위 순회 값과 후위 순회 값을 입력하였습니다";
            return subTree;
        }

        int rightNodeValue = *(find(postorder.begin(), postorder.end(), rootNode) - 1);
        vector<int>::iterator rightNode = find(subTree.begin(), subTree.end(), rightNodeValue);
        
        // 왼쪽 서브 트리의 값 넣기
        for (vector<int>::iterator it = subTree.begin() + 1; it != rightNode; it++) { leftSubTree.push_back(*it); }
        // 오른쪽 서브 트리의 값 넣기
        for (vector<int>::iterator it = rightNode; it != subTree.end(); it++){ rightSubTree.push_back(*it); }

        if (leftSubTree.size() == 1 && rightSubTree.size() == 1) // 서브트리 크기가 3일 경우 leftSubTree와 rootNode의 순서를 바꾼걸 리턴함
        {
            vector<int> temp;
            temp.push_back(leftSubTree[0]);
            temp.push_back(rootNode);
            temp.push_back(rightSubTree[0]);
            return temp;
        }
        else if (leftSubTree.empty() && rightSubTree.empty()) // 서브트리 크기가 1일 경우 rootNode만 리턴
        {
            vector<int> temp;
            temp.push_back(rootNode);
            return temp;
        }

        // 예외처리 코드 2
        else if (leftSubTree.empty())
        {
            cout << "트리는 포화이진트리와 완전이진트리 형식만 가능합니다";
            return subTree;
        }

        leftSubTree = makeInorder(leftSubTree);
        rightSubTree = makeInorder(rightSubTree);

        vector<int> temp;
        for (int i = 0; i < leftSubTree.size(); i++)
        {
            temp.push_back(leftSubTree[i]);
        }
        temp.push_back(rootNode);
        for (int i = 0; i < rightSubTree.size(); i++)
        {
            temp.push_back(rightSubTree[i]);
        }
        return temp;
    }
```

- 이진 트리에는 전위, 중위, 후위가 있는데 이 코드는 전위순회와 후위순회를 입력 받으면 중위순회를 출력해주는 코드이다.
- 전위순회의 규칙과 후위순회의 규칙을 이용해서 가장 밑에서 재귀함수를 이용해 리턴 받아가며 이진트리를 재현해내고 그대로 출력해서 중위 순회를 만들어 낼 수 있었다.

