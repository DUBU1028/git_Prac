//typedef struct선언과 struct 선언의 차이점: typedef struct선언은 별칭을 지정하여 main부분에서 struct를 사용할 필요 없이 별칭으로 바로 새로운 구조체를 생성가능
//반면 일반적인 struct선언은 별칭을 사용할 수 없음

typedef struct ttt{
    int data;
}ta;

struct sss{

    int memory;
}sa;

int main()
{
    struct ttt t1;
    struct sss s1;
    ta t2;
    //sa s2; - 오류!
    
    return 0;
}