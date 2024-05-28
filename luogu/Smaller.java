public class Smaller {
  public static class Node{
    private Node left;
    private Node right;
    private int leftnums;
    private int rightnums;
    private int val;
    private int times;
    
    Node(int leftnums, int rightnums, int val, int times){
      this.leftnums = leftnums;
      this.rightnums = rightnums;
      this.val = val;
      this.times = times;
    }
    public static void print(Node node, int depth){
      String blanks = "";
      for (int i=0; i<depth; i++){
        blanks += " ";
      }
      if (node == null){
        System.out.println(blanks +"[/]\n");
      } else {
        System.out.println(blanks + node.val);
        print(node.left, depth+1);
        print(node.right, depth+1);
      }
    }
    
    public void insert(int x){
      if (this.val == x){
        times++;
      } else if (x < this.val){
        this.leftnums++;
        if (this.left == null){
          this.left = new Node(0, 0, x, 1);
        } else {
          this.left.insert(x);
        }
      } else {
        this.rightnums++;
        if (this.right == null){
          this.right = new Node(0, 0, x, 1);
        } else {
          this.right.insert(x);
        }
      }
    }
    
    public int getValuesLessThan(int x){
      int result = 0;
      if (this.val < x){
        result = this.leftnums+this.times;
        if (this.right != null){
          result += this.right.getValuesLessThan(x);
        }
        return result;
      } else if (this.val == x){
        return this.leftnums;
      } else { // this.val < x
        if (this.left == null){
          return 0;
        } else {
          return this.left.getValuesLessThan(x);
        }
      }
    }
  }
	public static int[] smaller(int[] unsorted) {
	  int n = unsorted.length;
    int[] result = new int[n];
    result[n-1] = 0;
    Smaller.Node node = new Smaller.Node(0, 0, unsorted[n-1], 1);
    for (int i=n-2; i>=0; i--){
      //Smaller.Node.print(node, 0);
      result[i] = node.getValuesLessThan(unsorted[i]);
      node.insert(unsorted[i]);
    }
    return result;
  }     

  public static void main(String[] args) {
    int[] arr = new int[120000];
    
    int[] arr2 = smaller(arr);

  }
}