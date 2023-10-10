public class P1nX {
    public static void main(String[] args) {
        if (args.length < 6) {
            System.out.println("Uso: java P1nX <nome> <sobrenome> <dia> <mes> <ano> <genero (Homem ou Mulher)>");
            return;
        }

        Pessoa pessoaArgs = null;

        String nome = args[0];
        String sobreNome = args[1];
        int dia = Integer.parseInt(args[2]);
        int mes = Integer.parseInt(args[3]);
        int ano = Integer.parseInt(args[4]);
        
        if (args[5].equals("Homem")) {
            pessoaArgs = new Homem(nome, sobreNome, dia, mes, ano);
        } else if (args[5].equals("Mulher")) {
            pessoaArgs = new Mulher(nome, sobreNome, dia, mes, ano);
        } else {
            System.out.println("Genero invalido");

        }
        
        System.out.println(pessoaArgs.toString());


        // faltando rotina de entrada de dados pelo terminal
    }
}
