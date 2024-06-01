
class Test {
    public static void main(String[] args) {	
        int i = 0;
        int r = 0;

        r = (i++) + (i++) + (i++);

        System.out.println("i = " + i);
        System.out.println("r = " + r);

        r = (++i) + (++i) + (++i);

        System.out.println("i = " + i);
        System.out.println("r = " + r);
    }
}