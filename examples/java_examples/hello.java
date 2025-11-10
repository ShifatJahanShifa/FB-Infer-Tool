// Hello.java
// command: infer run -- javac Hello.java
class Hello {
  int test() {
    String s = null;
    return s.length();
    // return s == null ? 0 : s.length();
  }
}