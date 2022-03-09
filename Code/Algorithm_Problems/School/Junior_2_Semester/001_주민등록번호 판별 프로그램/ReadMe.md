```
    배열을 이용하여 주민등록번호 판별 프로그램 작성하기
```

- 풀이 코드

```cpp
    #include <iostream>
    #include <string>
    using namespace std;
    
    int main()
    {
        char MyNum[14];
        cout << "띄어쓰기 없이 주민번호 입력 : ";
        cin >> MyNum;
        string gender; char birthday[10]; int age;
    
        int Number[11]{ 8, 12, 15, 18, 25, 34, 39, 47, 54, 66, 90 };
        string area[11]{ "서울", "부산", "인천", "경기도", "강원도", "충청북도", "충청남도", "전라북도", "경상도" };
    
        if (MyNum[6] <= 2) 
        {
            birthday[0] = '1';
            birthday[1] = '9';
            birthday[2] = MyNum[0];
            birthday[3] = MyNum[1];
        }
        else 
        {
            birthday[0] = '2';
            birthday[1] = '0';
            birthday[2] = MyNum[0];
            birthday[3] = MyNum[1];
        }
    
        int ibirthyear = (birthday[0] - '0') * 1000 + (birthday[1] - '0') * 100 + (birthday[2] - '0') * 10 + (birthday[3] - '0') * 1;
        age = 2021 - ibirthyear + 1;
    
        if (MyNum[6] % 2 == 1)
            gender = "남자";
        else
            gender = "여자";
    
        int n = 0;
        string Sarea;
        for (int i = 0; i < 10; i++)
        {
            int in = ( MyNum[7] - '0' ) * 10 + MyNum[8] - '0';
            if (n < in && in <= Number[i])
                Sarea = area[i];
            n = Number[i];
        }
    
        int all = 0; int ex = 2;
        for (int i = 0; i < 12; i++)
        {
            all += (MyNum[i] - '0') * ex;
            cout << all << endl;
            ex++;
            if (ex == 10)
                ex = 2;
        }
        string isTrue;
        if (MyNum[12] - '0' == 11 - (all % 11))
            isTrue = "올바른 주민번호";
        else
            isTrue = "올바르지 못한 주민번호";
    
        cout << "성별 : " << gender << ", 나이 : " << age << ", 출생연도 : " << birthday[0] << birthday[1] << birthday[2] << birthday[3] << ", 출생지역 : " << Sarea << ", 주민등록번호 유효성 검사 : " << isTrue;
    
        //48 ~ 57
        return 0;
    }
```

- 입력된 주민등록번호의 정보를 가져와서 이 사람의 개인정보를 출력하고 이 주민등록번호가 올바른 것인지 확인해주는 코드이다.
- 주민등록번호 가지고 정보를 빼내야하기에 주민등록번호에 대해서 조사를 많이 하게 되었다. 이후에는 주민등록번호의 정보만 빼내면 되었기에 힘들이지 않고 할 수 있었다.