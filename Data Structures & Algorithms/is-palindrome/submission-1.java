class Solution {
    public static boolean isPalindrome(String s) {
        int len = s.length();
        if(s.isEmpty() || len == 1){
            return true;
        }

        String str = s.chars()
                .filter(c -> Character.isLetterOrDigit(c))
                .mapToObj(c -> String.valueOf((char) c).toLowerCase())
                .collect(Collectors.joining());

        len = str.length();

        for(int i = 0, j = len - 1; i <= j; i++, j--){
            if(str.charAt(i) != str.charAt(j)){
                return false;
            }
        }
        return true;
    }
}