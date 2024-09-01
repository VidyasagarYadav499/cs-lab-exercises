public class Matrix {
    public static int[][] multiply(int[][] a, int[][] b) {
        int row1 = a.length;
        int col1 = a[0].length;

        int row2 = b.length;
        int col2 = b[0].length;

        if (col1 != row2) {
            return null;
        }

        int[][] c = new int[row1][col2];

        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col2; j++) {
                for (int k = 0; k < col1; k++) {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }

        return c;
    }

    public static int[][] transpose(int[][] a) {
        int rows = a.length;
        int cols = a[0].length;

        int[][] b = new int[cols][rows];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                b[j][i] = a[i][j];
            }
        }

        return b;
    }

    public static int[][] add(int[][] a, int[][] b) {
        int row1 = a.length;
        int col1 = a[0].length;

        int row2 = b.length;
        int col2 = b[0].length;

        if (row1 != row2 || col1 != col2) {
            System.out.println("Dimensions are not same, addition is not possible.");
            System.exit(100);
        }

        int[][] c = new int[row1][col1];
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                c[i][j] = a[i][j] + b[j][i];
            }
        }

        return c;
    }
}