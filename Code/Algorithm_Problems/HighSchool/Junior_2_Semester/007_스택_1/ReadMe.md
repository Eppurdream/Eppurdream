```
    1. 스택 구현하기
    2. 숫자 거꾸로 출력하기(스택 사용)
    3. 세 정수 거꾸로 출력하기(스택 사용)
```

- 풀이 코드

```cpp
    // 1번 문제

    #include <iostream>
    using namespace std;
    
    template<typename T>
    class stack
    {
    private:
        T* arr;
        int isize;
        int maxSize;
    public:
        stack();
        stack(int s);
        ~stack();
        void push(T t);
        void pop();
        T top();
        int size();
        bool empty();
    };
    
    template<typename T>
    stack<T>::stack()
    {
        arr = (T*)malloc(sizeof(T) * 0);
        isize = 0;
        maxSize = 0;
    }
    
    template<typename T>
    stack<T>::stack(int s)
    {
        arr = (T*)malloc(sizeof(T) * s);
        isize = s;
        maxSize = s;
    }
    
    template<typename T>
    stack<T>::~stack()
    {
        free(arr);
    }
    
    template<typename T>
    void stack<T>::push(T t)
    {
        if (maxSize > isize)
        {
            isize++;
            arr[isize - 1] = t;
            return;
        }
        void* temp = realloc(arr, sizeof(T) * (isize + 1));
        if (temp == NULL)
        {
            return;
        }
        arr = (T*)temp;
        isize++;
        maxSize = isize;
        arr[isize - 1] = t;
    }
    
    
    template<typename T>
    void stack<T>::pop()
    {
        if (isize - 1 < 0)
        {
            return;
        }
        isize--;
    }
    
    template<typename T>
    T stack<T>::top()
    {
        return arr[isize - 1];
    }
    
    template<typename T>
    int stack<T>::size()
    {
        return isize;
    }
    
    
    template<typename T>
    bool stack<T>::empty()
    {
        if (isize == 0)
            return true;
        return false;
    }
    
    int main()
    {
        stack<int> st;
        st.push(5);
        st.push(6);
        st.push(7);
        st.push(8);
        st.push(9);
        int size = st.size();
        if (st.empty())
        {
            cout << "st가 비어있어요" << endl;
            return 0;
        }
    
        for (int i = 0; i < size; i++)
        {
            cout << st.top() << ", ";
            st.pop();
        }
        cout << endl;
    
        if (st.empty())
        {
            cout << "st가 비어있어요.." << endl;
        }
        st.push(3);
        cout << st.top() << endl;
        return 0;
    }
```

- c++ 에 있는 스택을 조금 참고해서 비슷하게 나마 만든 코드이다.
- 자료구조중 하나인 스택을 구현하기 위해서 있을거 없을거 다 찾아다니며 공부했었다. 그러면서 template도 알게 되었고 c의 문법인 malloc도 어쩌다 사용하게 되었다.
- 이 코드를 만들어가며 메모리 오류가 자주 발생하였는데 이걸 해결하느라 머리를 짜냈던 기억이 있다.
- 자료구조를 공부하고 만들다보니 함수나 변수의 이름을 정할 때 표준이 있다는 것을 알게 되었고 이것을 따라하게 되었다.

```cpp
    // 2번 문제

    #include <iostream> // 문제 1에서 만든거에요
    using namespace std;
    
    // 1번 문제 스택 코드 여기 있음 (너무 길어서 생략) ----------------------
    
    int main()
    {
        stack<char> st;
        char num[11] = { 'a', };
        cin >> num;
    
        for (int i = 0; i < 11; i++) 
        {
            st.push(num[i]);
        }
    
        for (int i = 0; i < 11; i++)
        {
            cout << st.top();
            st.pop();
        }
        return 0;
    }
```

- 입력 받은 수를 스택에 담아 pop시키며 출력하는 함수이다.
- 1번 문제에서 만든 스택을 이 문제에 사용했을 때 잘 작동하는 것을 보고 조금 뿌듯함을 느꼇었다.

```cpp
    // 3번 문제

    #include <iostream> // 문제 1에서 만든거에요
    using namespace std;
    
    // 1번 문제 스택 코드 여기 있음 (너무 길어서 생략) ----------------------
    
    int main()
    {
        stack<int> st;
        int num = 0;
        for (int i = 0; i < 3; i++)
        {
            cin >> num;
            st.push(num);
        }
        for (int i = 0; i < 3; i++)
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
```

- 정수 3개를 입력 받아서 그걸 스택에 넣은 뒤 그대로 pop하며 출력하는 코드이다.
- 1번 코드를 가져와서 코드를 작성하였고 스택 자료구조의 특징만 이용하면 풀 수 있는 문제이기에 간단히 풀었다.