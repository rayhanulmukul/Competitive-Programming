void Rabinkarp ( string pattern , string text){
int m = pattern . length ();
int n = text. length ();
int q = INT_MAX ;
int x = 11; // typically prime - multiplier
int x_m = 1; // xˆ(m -1) used for next hash computation
int hash_p = 0, hash_t = 0;
for(int i = 0; i < m - 1; i++){
x_m = (x_m * x) % q;
}
// compute hash for pattern and first window of text
for(int i = 0; i < m; i++){
hash_p = (x * hash_p + pattern [i]) % q;
hash_t = (x * hash_t + text[i]) % q;
}
for(int i = 0; i <= n - m; i++){
if( hash_p == hash_t ){ // check for character by character match
/* bool flag = true;
for(int j = 0; j < m; j++){
if(text[i + j] != pattern [j]){
flag = false ;
break ;
}
}
if(flag){
2.6. STRING 11
cout << " Pattern found at index " << i << endl;
}*/
cnt ++;
}
// if it was not last window , then continue hash computation
if(i < n - m){
hash_t = (x * ( hash_t - text[i] * x_m) + text[i + m]) % q;
if( hash_t < 0){
hash_t += q;
}
}
}
}
void solve (int tt){
string pattern = "abc";
string text = " ababcababcabc ";
Rabinkarp (pattern , text);
}