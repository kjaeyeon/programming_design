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
//게임 설명 화면
//게임 스토리
ㅀㄹㅇㅎ
//타이머 설정
//팩맨의 생성
//팩맨의 움직임
void packman_move(){
while(game_start){
   if(벽이 있는 곳으로 방향키를 눌렀다면) //벽의 좌표와 자신의 좌표를 비교해 같다면
      printf("벽은 넘을수 없다");
      continue;
   else if(오른쪽 방향키를 눌렀다면) //입력한 키와 오른쪽 키의 아스키 코드가 같다면
      gotoxy(x+1,y); //오른쪽으로 한칸
   else if(왼쪽 방향키를 눌렀다면) 
      gotoxy(x-1,y);
   
}
//고스트 생성
//고스트의 움직임

//메인 함수
int main(){
   game_menu();
}

//미로 만들기
   //초기 미로 생성
   //벽 뚫기 위해 랜덤으로 위치 선정


//미로 세팅하기
//미로 출력하기
//미로 실행하기
//블럭 체크
//게임 종료 조건
//아이템 추가
//bgm 추가
//공포 이미지 추가
//시야 제한
//게임 결과 화면
//명예의 전당 화면

//goto 함수 제작
void gotoxy(int x, int y){
   COORD Pos={x-1, y-1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
*/
