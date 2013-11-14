import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class QSort {

	private ArrayList<Integer> A;
	
    public static void main(String[] args) {
            QSort q = new QSort();
            q.quicksort();
            q.print();
    }
    
	public QSort() {
		try {
			A = new ArrayList<Integer>();
			
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			
			String line;
			while ((line = br.readLine()) != null) {
				A.add(Integer.valueOf(line));
			}
		}
        catch (IOException e) {
            e.printStackTrace();
        }
	}
	
    public void print() {
        for (int i : A) {
            System.out.print(i + "\n");
        }
        System.out.println();
    }
    
    public void quicksort() {
        this.quicksort(0, A.size()-1);
    }
    
    public void quicksort(int p, int r) {
        if (p < r) {
            int q = partition(p, r);
            quicksort(p, q-1);
            quicksort(q+1, r);
        }
    }
    
    public int partition(int p, int r) {
        int x = A.get(r);
        int i = p - 1;
        for (int j = p ; j < r ; j++) {
            if (A.get(j) <= x) {
                i++;
                swap(i, j);
            }
        }
        swap(i+1, r);
        return i+1;
    }
    
    public void swap(int a, int b) {
        int temp = A.get(a);
        A.set(a, A.get(b));
        A.set(b, temp);
    }
}
