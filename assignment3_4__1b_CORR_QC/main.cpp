#include <iostream>
#include <fstream>

class Address{
   //public:
   //std::string city, street; //LEADS TO RUN-TIME CRASH!!
   char city[100];
   char street[100];
   int building, app;
   public:
   /*Address(std::string city, std::string street,
            int building, int app){
     this->city = city;
     this->street = street;
     this->building = building;
     this->app = app;
   }*/
   Address(std::ifstream& fin){
     fin >> city >> street
        >>building >> app;
   }
   std::string ret_string(){
     /*return city + ", " +
            street + ", " +
            std::to_string(building) + ", " +
            std::to_string(app) + "\n";*/
     std::string retstring; //NEEDED TO START CONCATENATING IN THE C++ STYLE
     return retstring + city + ", " +
            street + ", " +
            std::to_string(building) + ", " +
            std::to_string(app) + "\n";
   }
};

int main() {
  std::ifstream fin("in.txt");
  int num;
  //Address** addrs;
  Address* addrs;
  if(fin.is_open()){
     //std::string input;
    //int num;
    fin >> num;
    //addrs = new Address*[num];
    addrs = (Address*)malloc(sizeof(Address)*num);
    for(int i{};i<num&&fin;i++){
      addrs[i] = Address(fin);
    }
  }else{
    std::cout<<"Couldn't open file!\n";
  }
  fin.close();
  std::ofstream outfile("out.txt");
  outfile << num << "\n";
  for(int i=num-1;i>=0;i--){
      outfile << addrs[i].ret_string();
  }
  outfile.close();
  /*for(int i{};i<num;i++){
    delete addrs[i];
  }*/
  free(addrs);

  return 0;
}
