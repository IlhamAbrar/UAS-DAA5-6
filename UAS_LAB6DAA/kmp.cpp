#include<iostream>
using namespace std;

void findPrefix(string pattern, int m, int prefArray[]) {
   int length = 0;
   prefArray[0] = 0;     //posisi pertama selalu 0 karena belum ada prefix/awalan

   for(int i = 1; i<m; i++) {
      if(pattern[i] == pattern[length]) {
         length++;
         prefArray[i] = length;    
      }else {
         if(length != 0) {
            length = prefArray[length - 1];
            i--;     //kurangi nilai i untuk menghindari efek peningkatan nilai setelah iterasi
         }else
            prefArray[i] = 0;
      }
   }
}

void kmpPattSearch(string mainString, string pattern, int *locArray, int &loc) {
   int n, m, i = 0, j = 0;
   n = mainString.size();
   m = pattern.size();
   int prefixArray[m];    //prefix array sama size nya dengan pattern
   findPrefix(pattern, m, prefixArray);
   loc = 0;

   while(i < n) {
      if(mainString[i] == pattern[j]) {
         i++; j++;
      }

      if(j == m) {
         locArray[loc] = i-j;      //item ditemukan pada posisi i-j 
         loc++;
         j = prefixArray[j-1];    //ambil panjang prefix dari array 
      }else if(i < n && pattern[j] != mainString[i]) {
         if(j != 0)
            j = prefixArray[j-1];
         else
            i++;
      }
   }
}

int main() {
   string str = "qpmmievsfegoiandsasotoogarasipakdinabcdeqwertydjisas";
   string patt = "mie";
   int locationArray[str.size()];
   int index;
   kmpPattSearch(str, patt, locationArray, index);

   for(int i = 0; i<index; i++) {
      cout << "Pattern ketemu gan di lokasi: " <<locationArray[i] << endl;
   }
}