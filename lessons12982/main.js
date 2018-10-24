function solution(d, budget) {
    var answer = 0;
    var size = d.length;
    d.sort((a,b)=>(a-b))
    for(var i=0;i<size;i++){
        budget-=d[i];
        if(budget<0){
            break;
        }else{
            answer++;
        }
    }
    return answer;
}
