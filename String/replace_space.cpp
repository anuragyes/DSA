/*



#include <bits/stdc++.h> 
string replaceSpaces(string &str){
   string s = "";

    for(int i =0;i<str.length();i++){
		 if(str[i]==' '){
			 s.push_back('@');
			  s.push_back('4');
			   s.push_back('0');
		 }else{
			 s.push_back(str[i]);
		 }
	}
	 return s;


    //  *****************************
    	//  without using extra space 
	
	 for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            // Replace space with "@40"
            str.replace(i, 1, "@40");
            // Move the index forward by 2 to skip past "@40"
            i += 2;
        }
    }
	  return str;
}*/