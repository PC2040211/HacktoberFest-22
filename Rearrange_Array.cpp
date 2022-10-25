void arrange(vector<int> &A) {
   int n=A.size();
    for(int i=0;i<n;i++){
        if(A[i]>=i){
            A[i]=n*(A[i])+A[A[i]];
        }
        else{
            A[i]=n*A[i]+(A[A[i]]/n);
        }
    }
    for(int i=0;i<n;i++){
        A[i]=A[i]%n;
    }

}
