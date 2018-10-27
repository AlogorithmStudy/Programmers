function solution(p, c) {
    var size = c.length;
    p.sort((a,b)=>(a < b ? -1 : (a > b ? 1 : 0)));
    c.sort((a,b)=>(a < b ? -1 : (a > b ? 1 : 0)));
    for(var i=0;i<size;i++){
        if(p[i]!=c[i]){
            return p[i];
        }
    }   
    return p[size];
}
