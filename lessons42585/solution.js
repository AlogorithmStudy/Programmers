var isLaser = (arr, i)=>(arr[i] == "(" && arr[i+1] != undefined && arr[i+1] == ")");

function solution(arr) {
    var answer = 0; 
    var stack = [];
    var size = arr.length;
    for(var i = 0 ; i < size ; ++i ){
        if(isLaser(arr,i)){
            ++i;
            answer+=stack.length;
        }else if(arr[i] == "("){
            stack.push(i);
            answer++;
        }else{
            stack.pop(); 
        }
    }
    return answer;
}
