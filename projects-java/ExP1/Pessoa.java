import java.util.Calendar;
import java.util.GregorianCalendar;

public class Pessoa {
    private String nome;
    private String sobrenome;
    private GregorianCalendar dataNascimento;
    private float altura;
    private float peso;
    private char genero;
    private static int contadorPessoas;
    private Pessoa pai;
    private Pessoa mae;
    private String status;


    //construtor

    public Pessoa() {
        contadorPessoas++;
 

        nome = "indefinido";
        sobrenome = "indefinido";
        dataNascimento = new GregorianCalendar(2000, 0, 1);
        altura = 1.0f;
        peso = 20.0f;
        genero = 'M';
        pai = null;
        mae = null;
        status = "vivo";
    }

    public Pessoa(String nome) {
        this();
        setNome(nome);
  
    }
    
    public Pessoa(String nome, String sobrenome, int ano, int mes, int dia, float altura, float peso, char genero,
            Pessoa pai, Pessoa mae, String status) {
        setNome(nome);
        setSobrenome(sobrenome);
        setDataNascimento(ano, mes, dia);
        setAltura(altura);
        setPeso(peso);
        setGenero(genero);
        setPai(pai);
        setMae(mae);
        setStatus(status);
        contadorPessoas++;
 

    }

    //setter

    public void setNome(String nome) {
        if ((nome.length()) > 0) {
            this.nome = nome;
        }
    }

    public void setSobrenome(String sobrenome) {
        if ((sobrenome.length()) > 0) {
            this.sobrenome = sobrenome;
        }

    }

    // ano/mes/dia
    public void setDataNascimento(int ano, int mes, int dia) {
        if (ano > 1900 && ano < 2020 && mes > 0 && mes < 13 && dia > 0 && dia < 32) {
              dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
        }

      
    }
    

    public void setPeso(float peso) {
        if (peso > 20) {
            this.peso = peso;
        }
    }

    public void setAltura(float altura) {
        if (altura > 1) {
            this.altura = altura;
        }
    }

    public void setGenero(char genero) {
        this.genero = genero;
    }

    public void setMae(Pessoa mae) {
        if (mae == null) {
            mae = new Pessoa();
            mae.setNome("indefinido");
        }
        this.mae = mae;
    }


    public void setPai(Pessoa pai) {
        if (pai == null) {
            pai = new Pessoa();
            pai.setNome("indefinido");
        }
        this.pai = pai;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    //getter
    public String getNome() {
        return nome;
    }

    public String getSobrenome() {
        return sobrenome;
    }

    public GregorianCalendar getDataNascimento() {
        return dataNascimento;
    }
    
    public float getPeso() {
        return peso;
    }

    public float getAltura() {
        return altura;
    }

    public char getGenero() {
        return genero;
    }

    public Pessoa getMae() {
        return mae;
    }

    public Pessoa getPai() {
        return pai;
    }

    public String getStatus() {
        return status;
    }

    public static int getContadorPessoas() {
        return contadorPessoas;
    }

    // metodos

    private int calcularIdade() {
        Calendar hoje = Calendar.getInstance();
        int idade = hoje.get(Calendar.YEAR) - dataNascimento.get(Calendar.YEAR);

        if (hoje.get(Calendar.MONTH) < dataNascimento.get(Calendar.MONTH)) {
            idade--;
        }

        return idade;
    }

    public String toString() {
        String dados = "Nome: " + nome + " \n";
        dados += "Sobrenome: " + sobrenome + "\n";
        dados += "Idade: " + calcularIdade() + " anos\n";

        if (mae != null && mae.getNome() != "indefinido") {
            dados += "Mãe: " + mae.getNome() + "\n";
        }

        if (pai != null && pai.getNome() != "indefinido") {
            dados += "Pai: " + pai.getNome() + "\n";
        }

        dados += "Status: " + status + "\n";
        dados += "Idade: " + calcularIdade() + " anos\n";
        dados += "Peso: " + peso + " kg\n";
        dados += "Altura: " + altura + " m\n";
        dados += "Genero: " + genero + "\n";


        return dados;
        }
       
    }

