#include <string>

class BlackholeConstants{
  public:
  std:: string filename[15];
  int filename_length = 15;
  double changetime = 0.1;
  
  BlackholeConstants(){
    for (int i = 0; i < filename_length; i++) filename[i] = std::to_string(i)+".png";
  }
};
