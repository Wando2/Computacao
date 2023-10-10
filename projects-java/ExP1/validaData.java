public class validaData {
    public static boolean isDia(String data) {
        if (data.length() > 2) {
            return false;
        }
        int dia = Integer.parseInt(data);

        if (dia < 1 || dia > 31) {
            return false;
        }

        return true;

    }
    
    public static boolean isMes(String mesString) {
        if (mesString.length() > 5) {
            return false;
        }
        int mes = Integer.parseInt(mesString);

        if (mes < 1 || mes > 12) {
            return false;
        }

        return true;

    }

    public static boolean isAno(String anoString) {
        if (anoString.length() > 10) {
            return false;
        }
        int ano = Integer.parseInt(anoString);

        if (ano < 1900 || ano > 2018) {
            return false;
        }

        return true;

    }
}
