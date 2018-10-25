Array.prototype.remove = function(index){
    this.splice(index, 1);
}
Object.prototype.appends = function(arr){
    var size = arr.length;
    for(var i=0; i<size; i++){
        this[this.length]=arr[i];
    }
}
/*
function solution(jobs) {
    var size = jobs.length;
    var answer = 0;
    var time = 0;
    jobs.sort((a,b)=>(a[1]-b[1]));
    while(jobs.length>0){
        var todo = jobs.filter(e=>(e[0]<=time));
        if(todo.length==0){
            time++;
        }else{
            var selected = todo[0];
            var index = jobs.indexOf(
                jobs.find(e=>
                          (e[0]==selected[0]
                           &&
                           e[1]==selected[1])
                         )
            );
            answer+=(time-selected[0]+selected[1]);
            time+=selected[1];
            jobs.remove(index);
        }
    }
    return parseInt(answer/size);
}*/

function solution(jobs) {
    var size = jobs.length;
    var answer = 0;
    var time = 0;
    console.log(jobs);
    jobs = jobs.map((e,i)=>({
        idx: i,
        start:e[0], 
        size:e[1]
    }));
    while(jobs.length > 0){
        
        // 할일: 이미 시작된 작업들
        var todo = jobs.filter(e=>e.start<=time);
        if(todo.length == 0){
            time++;
        }else if(todo.length == 1){
            var selected = todo.pop();
            answer+=(time-selected.start+selected.size);
            time+=selected.size;
            var idx = jobs.indexOf(
                jobs.find(e=>selected.idx == e.idx)
            );
            jobs.remove(idx);
        }else{
            // 시작된지 지난 시간이 제일 짧은 순서대로 정렬할 필요가 없음
            // todo.sort((a,b)=>((time-a.start)-(time-b.start)));
            // 길이가 짧은 순서대로 정렬 a,b a-b 오름차순
            todo.sort((a,b)=>(a.size-b.size));
            var selected = todo.shift();
            answer+=(time-selected.start+selected.size);
            time+=selected.size;
            var idx = jobs.indexOf(
                jobs.find(e=>selected.idx == e.idx)
            );
            jobs.remove(idx);
        }
    }
    answer=parseInt(answer/size);
    return answer;
}
