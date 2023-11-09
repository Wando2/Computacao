package ValidationContext;
public class ValidaData {
    public static boolean isDia(String data) {
        if (data.length() > 2) {
            System.out.println("Dia muito grande");
            return false;
        }
        int dia = Integer.parseInt(data);

        if (dia < 1 || dia > 31) {
            System.out.println("Dia invalido");
            return false;
        }
        return true;
    }

    public static boolean isDia(int dia) {
        if (dia < 1 || dia > 31) {
            System.out.println("Dia invalido");
            return false;
        }
        return true;
    }
    
    public static boolean isMes(String mesString) {
        if (mesString.length() > 5) {
            System.out.println("Mes muito grande");
            return false;
        }
        int mes = Integer.parseInt(mesString);

        if (mes < 1 || mes > 12) {
          System.out.println("Mes invalido");
          return false;
        }
        return true;
    }

    public static boolean isMes(int mes) {
        if (mes < 1 || mes > 12) {
          System.out.println("Mes invalido");
          return false;
        }
        return true;
    }

    public static boolean isAno(String anoString) {
        if (anoString.length() > 10) {
            System.out.println("Ano muito grande");
            return false;
        }
        int ano = Integer.parseInt(anoString);

        if (ano < 1900 || ano > 2018) {
          System.out.println("Ano invalido");
          return false;
        }
        return true;
    }

    public static boolean isAno(int ano) {
        if (ano < 1900 || ano > 2018) {
            System.out.println("Ano invalido");
            return false;
        }
        return true;
    }
}
