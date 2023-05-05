/*

//게임 메뉴
void game_menu(){
while(1){
   if(start를 선택한다면)
      retrun 0; //메뉴나가기
   else if(rule를 선택한다면)
      game_rule(); //rule 불러오기
   else if(exit를 선택한다면)
      exit(1); //나가기
}
//게임 시작 화면
int game_start(){
    switch(stage)
        case 2 : 아이템 생성;
        defalut :
            미로 호출;
            팩맨과 고스트 생성;
            목적지 생성;
            타이머 호출;
            
     게임 종료조건이 된다면
     return 0;
}
//게임 설명 화면
void game_rule(){
   printf("고스트는 당신에게 제일 빠른길로 다가오고 있습니다.\n 최대한 빨리 목적지를 향해 도망가세요!\n (황금열쇠)는 2스테이지에서 당신을 나가게 도와줄 것 입니다!");
}
//게임 스토리
void game_story(){
    printf("할로윈 파티를 초대받아 대저택에 갔더니 귀신들만 있는 곳이었다. 귀신을 피해 미로를 통과하여 대저택을 탈출해라!");
}
//타이머 설정
time_t start_time, end_time;
double stage1_time = 0, stage2_time = 0;
//(stage1)
printf("게임 시작\n");
start_time = time(NULL);
printf("게임 종료\n");
end_time = time(NULL);
stage1_time = difftime(end_time, start_time);
//(stage2)
printf("게임 시작\n");
start_time = time(NULL);
printf("게임 종료\n");
end_time = time(NULL);
stage2_time = difftime(end_time, start_time);
//(총 시간)
double total_time = stage1_time + stage2_time;
printf("총 시간: %.2f초\n");
return 0;
//팩맨의 생성
int packman_create(int x, int y){
    gotoxy(x,y);
    printf("(팩맨)");
    return 1;
}
//팩맨 삭제
void packman_remove(int x, int y){
    gotoxy(x,y);
    printf("\0");
    
}
//팩맨의 움직임
void packman_move(){
while(game_start()){
   if(벽이 있는 곳으로 방향키를 눌렀다면) //벽의 좌표와 자신의 좌표를 비교해 같다면
      printf("벽은 넘을수 없다");
      continue;
   else if(오른쪽 방향키를 눌렀다면) //입력한 키와 오른쪽 키의 아스키 코드가 같다면
      remove_packman(x,y);
      gotoxy(x+1,y); //오른쪽으로 한칸
      create_packman(x,y);
      
      
   else if(왼쪽 방향키를 눌렀다면) 
      remove_packman(x,y); //현재위치?
      gotoxy(x-1,y); //왼쪽으로 한칸
      create_packman(x,y);

   else if(왼쪽 방향키를 눌렀다면) 
      remove_packman(x,y);
      gotoxy(x,y+1); //위쪽으로 한칸
      create_packman(x,y);

    else if(왼쪽 방향키를 눌렀다면) 
      remove_packman(x,y);
      gotoxy(x,y-1); //아래쪽으로 한칸
      create_packman(x,y);
}
//고스트 생성
void ghost_create(int x, int y){
    gotoxy(x,y); 
    printf("(호박)");
}
//고스트의 움직임
void ghost_move(){
    while(game_start()){
        if(팩맨이 움직였다면)
            ghost_movement++; //변수 1 증가
        if(ghost_movement%3==0) //3번 증가하면 작동
            팩맨이 있는 방향으로 1칸 움직이기;
    }

}
   
}
//메인 함수
int main(){
   game_menu();
}

//미로 만들기
void maze(){
    srand((unsigned)time(NULL));//미로값 초기화
    //미로크기 설정
    int length, width;//길이와 폭 설정
    system("cls");
    create_maze();
    maze_set();
    print_maze();
//미로만들기
void create_maze(){
    for (int i = 0; i < 길이; i++) {
		for (int j = 0; j < 폭; j++) {
			if (길이,폭이 모두 짝수일때) 
            {
				벽을 만듦;
			}
			else if (길이가 짝수, 폭이 홀수일때) 
            {
				벽을 만듦;
			}
			else if (길이가 홀수, 폭이 짝수일때)  
            {
				벽을 만듦;
			}
			else //길이,폭이 모두 홀수 일때
            {
				길을 만듦;
			}
		}
	}
    // 길이,폭이 홀수 일때 길이 만들었으니 길 사이사이 벽을 뚫어 미로를 만들기 위해 랜덤으로 길 위치 선정
    int rand_length, rand_width;
    do {
        rand_length = rand() % length;
        rand_width = rand() % width;
    } while (랜덤으로 생성한 길이 폭이 짝수일때);
    랜덤으로 벽을 뚫음;
}

//미로 설정
void maze_set() {
    maze[1][1] = 팩맨 생성;
    pos_random(목적지 생성); 
    pos_random(고스트생성);
}
//미로 출력
void print_maze() {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            if (팩맨) text_color(연두색, 회색);
            else if (목적지) text_color(노란색, 회색);
            else if (고스트) text_color(빨간색, 회색);
            else if (길) text_color(회색, 회색);
            else text_color(파란색, 파란색);//벽
            cout << maze[i][j];
        }
        cout << "\n";
    }
}
//블럭 체크
//게임 종료 조건
bool clear(int stage){
switch(stage){
//(stage1)
case 1 :
   if(고스트의 위치와 팩맨의 위치가 같아지면)
   	printf("탈출 실패");
  	retrun 0;
   else if(팩맨이 골인 지점에 들어간다면)
 	return 1;
//(stage2)
case 2:
	if(고스트의 위치와 팩맨의 위치가 같아지면)
   	printf("탈출 실패");
  	retrun 0;
   else if(팩맨이 골인 지점에 들어간다면)
 	if(열쇠를 가지고 있는가?)
		return 1;
	else
		printf("열쇠를 가지고 와야 나갈 수 있다.");
		return 0;
    }
}
//아이템 추가
//아이템위치생성
int item_row, item_col; //아이템의 생성위치

//행과 열에서 랜덤위치생성
void choose_random_location(int* row, int* col) {
    do {
        *row = rand() % ROW; //행에서 랜덤포인터지정
        *col = rand() % COL; //열에서 랜덤포인터지정
    } while (map[*row][*col] == 0); //이미 길인 경우는 제외
}

//황금열쇠 생성
void gold_item(){

//랜덤한 위치 선택
choose_random_location(&item_row, &item_col);

//선택한 위치에 황금열쇠 생성
map[item_row][item_col] = 2;}//2는 황금열쇠로 출력 맵에서 0은 길, 1은 벽이다.

//공포bgm 추가
//헤더파일추가 #include<Windows.h>, #include <mmsystem.h>
//Windows API를 사용해 공포 BGM파일을 불러온다.
BOOL PlaySound(
    LPCTSTR 재생할 사운드 파일의 경로,
    HMODULE 사운드파일이 들어있는 모듈의 핸들(NULL사용)
    DWORD SND_ASYNC
);
//공포BGM 불러와서 비동기적 재생
int main() {
    PlaySound(유니코드변환("공포 BGM"), NULL, SND_ASYNC);

    // 게임 로직 등...

    PlaySound(NULL, NULL, 0); // BGM 중지

    return 0;
}

//공포 이미지 추가
//시야 제한 ->코딩 후 문제점이 발생하면 그래픽 함수 사용
void display(int x, int y) {
    for (int i = x - 2; i <= x + 2; i++) {
        for (int j = y - 2; j <= y + 2; j++) {
            if (i >= 0 && i < ROW && j >= 0 && j < COL) { // 미로 범위 내에서만 출력
                if (i == x && j == y) { 
                    printf("@"); //현재 위치
                } else if (maze[i][j] == WALL) { 
                    printf("■"); //벽
                } else { // 길은 공백으로 표시
                    printf(" ");
                }
            }
        }
        printf("\n"); // 한 줄 출력 후 개행
    }
}
//클리어 시간 출력
stage_clear_time = stage1_time + stage2_time
int clear_minutes = stage_clear_time/60;
int clear_second = stage_clear_time%60;
printf("클리어 하는데 %d분 %d초 걸렸습니다.\n", clear_minute, clear_second);


//명예의 전당 화면
#define SIZE 10
int all_time[SIZE]; //클리어 시간이 들어있는 배열
int i, j, min, temp;
for(i = 0; i < SIZE; i++){
    min = i;
    for(j=i+1; j<SIZE; j++){
        if(all_time[j]<all_time[min]){
            min = j;
        }
    }
    temp = all_time[i];
    all_time[j] = all_time[min];
    all_time[min] = temp;
}
printf("순위\n");
for(i=0; i<3; i++){
    printf("%d\n",all_time[i]);
    }
}

//goto 함수 제작
void gotoxy(int x, int y){
   COORD Pos={x-1, y-1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
*/
