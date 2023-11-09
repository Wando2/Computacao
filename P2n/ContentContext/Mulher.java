package ContentContext;
public class Mulher extends PessoaIMC {
    public Mulher(String nome, String sobreNome, int dia, int mes, int ano, float peso, float altura, long cpf) {

        super(nome, sobreNome, dia, mes, ano, peso, altura, cpf);

    }


    public Mulher(String nome, String sobreNome, int dia, int mes, int ano, float peso, float altura) {

        super(nome, sobreNome, dia, mes, ano, altura, peso);

    }

    public Mulher() {

        super();

    }

    @Override
    public String resultIMC() {
        float imc = calculaIMC();
        if (imc < 19) {
            return String.format("%.1f - Abaixo do peso ideal", imc);
        } else if (imc >= 19 && imc <= 25.8) {
            return String.format("%.1f - Peso ideal", imc);
        } else {
            return String.format("%.1f - Acima do peso ideal", imc);
        }
    }
}
