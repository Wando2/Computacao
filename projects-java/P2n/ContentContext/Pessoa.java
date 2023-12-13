package ContentContext;
import java.util.GregorianCalendar;

import ValidationContext.ValidaCPF;

import java.util.Calendar;

public class Pessoa {
    protected String nome;
    protected String sobreNome;
    protected GregorianCalendar dataNascimento;
    protected long cpf;
    private static int totalPessoas = 0;

    public Pessoa(String nome, String sobreNome, int dia, int mes, int ano) {
        this.nome = nome;
        this.sobreNome = sobreNome;
        this.dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
        totalPessoas++;

    }

    public Pessoa(String nome, String sobreNome, int dia, int mes, int ano, long cpf) {
        this(nome, sobreNome, dia, mes, ano);
      
        this.cpf = cpf;
        totalPessoas++;

    }

    public Pessoa() {
        totalPessoas++;
    }

    public boolean setNome(String nome) {
        if (nome.length() > 30) {
            System.out.println("Nome muito grande");
            return false;
        } else {
            this.nome = nome;
            return true;
        }

    }

    public boolean setSobreNome(String sobreNome) {
        if (sobreNome.length() > 30) {
            System.out.println("Sobrenome muito grande");
            return false;
        } else {
            this.sobreNome = sobreNome;
            return true;
        }

    }

    public boolean setDataNascimento(int dia, int mes, int ano) {
        if (ano <= 1900 || ano >= 2020) {
            System.out.println("Ano invalido");
            return false;
        }
        
        if (mes <= 0 || mes >= 13) {
            System.out.println("Mes invalido");
            return false;
        }

        if (dia <= 0 || dia >= 32) {
            System.out.println("Dia invalido");
            return false;
        }

        if (ano > 1900 && ano < 2020 && mes > 0 && mes < 13 && dia > 0 && dia < 32) {
            dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
            return true;
        }
        
        return false;
    }

    public boolean setCpf(String cpf) {
        long cpfLong = ValidaCPF.toLong(cpf);
        if (cpfLong == 0) {
            System.out.println("CPF invalido");
            return false;
        } else {
            this.cpf = cpfLong;
            return true;
        }
    }

    public boolean setCpf(long cpf) {
        if (ValidaCPF.isCPF(String.valueOf(cpf))) {
            this.cpf = cpf;
            return true;
        } else {
            System.out.println("CPF invalido");
            return false;
        }
    }

    public static void incrementarPessoa() {
        totalPessoas++;
    }

    // getter

    public String getNome() {
        return nome;
    }

    public String getSobreNome() {
        return sobreNome;
    }

    public String getDataNascimento() {
        int dia = dataNascimento.get(GregorianCalendar.DAY_OF_MONTH);
        int mes = dataNascimento.get(GregorianCalendar.MONTH) + 1;
        int ano = dataNascimento.get(GregorianCalendar.YEAR);
        return String.format("%02d/%02d/%04d", dia, mes, ano);
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

    public String getGenero() {
        if (this instanceof Homem) {
            return "Homem";
        } else if (this instanceof Mulher) {
            return "Mulher";
        } else {
            return "Unknown";
        }
    }

    public String toString() {
        String dados = "Nome: " + nome + " " + sobreNome + "\nData de Nascimento: "
                + getDataNascimento() + "\nIdade: " + calcularIdade() + "\nGenero: " + getClass().getName();
       
       if (cpf > 0) {
           dados += "\nCPF: " + ValidaCPF.imprimeCPF(String.valueOf(cpf));
       }
      

       
      return dados;
    }

}