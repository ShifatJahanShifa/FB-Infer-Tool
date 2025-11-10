// annotation


public class Test2 {
    public static void main(String[] args) throws RuntimeException {
        throw new RuntimeException("Stop here");
        // Infer can warn that the following line is unreachable
        System.out.println("This will never execute");
    }
}
