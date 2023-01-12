struct ArrayNode{
    int val;
    int gen=-1;
};
struct Array{
    ArrayNode _[MAXN];
    int gen=0;
    void zero(){
	gen++;
    }
    int get(int pos){
        if(_[pos].gen==gen){
            return _[pos].val;
        }else{
	   return 0;
        }
    }
    void set(int pos,int val){
        _[pos].gen=gen;
        _[pos].val=val;
    }
};