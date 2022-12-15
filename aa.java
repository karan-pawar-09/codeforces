class aa {

    static int length(String s) {
        int i = 0;
        for(char c: s.toCharArray()) {
            i++;
        }
        return i;
    }

    public static void main(String args[]) {
        System.out.println(length("KKSS"));
    }
}