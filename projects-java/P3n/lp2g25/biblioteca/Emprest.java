package lp2g25.biblioteca;
import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class Emprest implements Serializable {
    private  GregorianCalendar dataEmprestimo;
    private GregorianCalendar dataDevolucao;
    private String codigoLivro;

    @Override
    public String toString() {
       SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
    String dataEmprestimoStr = sdf.format(dataEmprestimo.getTime());

    
    Calendar dataDevolucaoPrevista = (Calendar) dataEmprestimo.clone();
    dataDevolucaoPrevista.add(Calendar.DAY_OF_MONTH, 7);
    String dataDevolucaoPrevistaStr = sdf.format(dataDevolucaoPrevista.getTime());

    String dataDevolucaoStr = dataDevolucao != null ? sdf.format(dataDevolucao.getTime()) : "Livro ainda nao devolvido";

    return "Emprest{" +
            "dataEmprestimo=" + dataEmprestimoStr +
            ", dataDevolucaoPrevista=" + dataDevolucaoPrevistaStr +
            ", dataDevolucao=" + dataDevolucaoStr +
            ", codigoLivro='" + codigoLivro + '\'' +
            '}';
    }
    

    public Emprest(GregorianCalendar dataEmprestimo, String codigoLivro) {
        this.dataEmprestimo = dataEmprestimo;
        this.codigoLivro = codigoLivro;
    }


    public GregorianCalendar getDataEmprestimo() {
        return dataEmprestimo;
    }


    public void setDataEmprestimo(GregorianCalendar dataEmprestimo) {
        this.dataEmprestimo = dataEmprestimo;
    }

    public GregorianCalendar getDataDevolucao() {
        return dataDevolucao;
    }

    public void setDataDevolucao(GregorianCalendar dataDevolucao) {
        this.dataDevolucao = dataDevolucao;

    }
    
    public String getCodigoLivro(){
        return codigoLivro;
    }

    

}