
import java.util.GregorianCalendar;
import java.util.Calendar;

public class Pessoa {
    private String nome;
    private String sobreNome;
    private GregorianCalendar dataNascimento;
    private float altura;
    private float peso;
    private long cpf;
    private static int totalPessoas = 0;

    public Pessoa(String nome, String sobreNome, int dia, int mes, int ano) {
        this.nome = nome;
        this.sobreNome = sobreNome;
        this.dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
        totalPessoas++;

    }

    public Pessoa(String nome, String sobreNome, int dia, int mes, int ano, float altura, float peso, long cpf) {
        this(nome, sobreNome, dia, mes, ano);
        this.peso = peso;
        this.cpf = cpf;
        totalPessoas++;

    }

    public void setNome(String nome) {
        if (nome.length() > 30) {
            System.out.println("Nome muito grande");
        } else {
            this.nome = nome;
        }

    }

    public void setSobreNome(String sobreNome) {
        if (sobreNome.length() > 30) {
            System.out.println("Sobrenome muito grande");
        } else {
            this.sobreNome = sobreNome;
        }

    }

    public void GregorianCalendar(int dia, int mes, int ano) {
        if (ano > 1900 && ano < 2020 && mes > 0 && mes < 13 && dia > 0 && dia < 32) {
            dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
        }
    }

    public void setAltura(float altura) {
        if (altura > 0 && altura < 3) {
            this.altura = altura;
        }

        if (altura > 3) {
            this.altura = altura / 100;
        }
    }

    public void setPeso(float peso) {
        if (peso > 0 && peso < 300) {
            this.peso = peso;
        }
    }

    public void setCpf(String cpf) {
        this.cpf = ValidaCPF.toLong(cpf);

    }

    public void setCpf(long cpf) {
        this.cpf = cpf;

    }

    // getter

    public String getNome() {
        return nome;
    }

    public String getSobreNome() {
        return sobreNome;
    }

    public GregorianCalendar getDataNascimento() {
        return dataNascimento;
    }

    public float getAltura() {
        return altura;
    }

    public float getPeso() {
        return peso;
    }

    public long getCpf() {
        return cpf;
    }

    public static int numPessoas() {
        return totalPessoas;
    }

    public int calcularIdade() {
        Calendar hoje = Calendar.getInstance();
        int idade = hoje.get(GregorianCalendar.YEAR) - dataNascimento.get(GregorianCalendar.YEAR);

        return idade;

    }

    public String toString() {
        String dados = "Nome: " + nome + " " + sobreNome + "\nData de Nascimento: "
                + dataNascimento.get(GregorianCalendar.DAY_OF_MONTH) + "/"
                + (dataNascimento.get(GregorianCalendar.MONTH) + 1) + "/" + dataNascimento.get(GregorianCalendar.YEAR) + "\nIdade: " + calcularIdade() + "\nGenero: " + getClass().getName();
        
       if(altura > 0){
         dados += "\nAltura: " + altura;
       }

       if(peso > 0){
           dados += "\nPeso: " + peso;
       }

       if (cpf > 0) {
           dados += "\nCPF: " + ValidaCPF.imprimeCPF(String.valueOf(cpf));
       }
      

       
      return dados;
    }

}