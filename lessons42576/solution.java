import java.util.Arrays;

class Solution {
    public String solution(String[] participant, String[] completion) {
        int c_size = completion.length;
        
        // O(nlogn) 
        Arrays.sort(participant);
        Arrays.sort(completion);
        
        for(int i=0;i<c_size;i++){
            if(!participant[i].equals(completion[i])){
                return participant[i];
            }
        }
        
        return participant[c_size];
    }
}
