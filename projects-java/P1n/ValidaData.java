public class ValidaData {
    public static void isDia(String data) {
        if (data.length() > 2) {
            System.out.println("Dia muito grande");
        }
        int dia = Integer.parseInt(data);

        if (dia < 1 || dia > 31) {
            System.out.println("Dia invalido");
        }

        

    }

    public static void isDia(int dia) {
        if (dia < 1 || dia > 31) {
            System.out.println("Dia invalido");
        }

      
    }
    
    public static void isMes(String mesString) {
        if (mesString.length() > 5) {
            System.out.println("Mes muito grande");
        }
        int mes = Integer.parseInt(mesString);

        if (mes < 1 || mes > 12) {
          System.out.println("Mes invalido");
        }

        

    }

    public static void isMes(int mes) {
        if (mes < 1 || mes > 12) {
          System.out.println("Mes invalido");
        }

        

    }



    public static void isAno(String anoString) {
        if (anoString.length() > 10) {
            System.out.println("Ano muito grande");
        }
        int ano = Integer.parseInt(anoString);

        if (ano < 1900 || ano > 2018) {
          System.out.println("Ano invalido");
        }

        

    }

    public static void isAno(int ano) {
        if (ano < 1900 || ano > 2018) {
            System.out.println("Ano invalido");
        }

        

    }
}
