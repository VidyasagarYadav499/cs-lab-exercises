public class MatrixMain {
    public static void main(String[] args) {
        int[][] a = {{1, 2}, 
                     {3, 4}
                    };
        
        int[][] b = {{1, 2},
                     {3, 4}
                    };

//        int[][] c = Matrix.multiply(a, b);
//
//        if (c == null) {
//            System.out.println("Multiplication is not possible.");
//            return;
//        }
//
//        for (int i = 0; i < c.length; i++) {
//            for (int j = 0; j < c[0].length; j++) {
//                System.out.print(c[i][j] + "\t");
//            }
//            System.out.println();
//        }

//        int[][] c = Matrix.transpose(a);
//        for (int i = 0; i < c.length; i++) {
//            for (int j = 0; j < c[0].length; j++) {
//                System.out.print(c[i][j] + "\t");
//            }
//            System.out.println();
//        }

        int[][] c = Matrix.add(a, b);
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < c[0].length; j++) {
                System.out.print(c[i][j] + "\t");
            }
            System.out.println();
        }

    }
}