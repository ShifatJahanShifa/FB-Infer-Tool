public class Test1 {
    public static void main(String[] args) {
        nullPointerDereference();
    }

    private static void nullPointerDereference() {
        String str = null;
        int length = str.length();
    }
}
