package ContentContext;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;


public class MinhaListaOrdenavel {
    private List<PessoaIMC> lista;

    public MinhaListaOrdenavel() {
        lista = new ArrayList<PessoaIMC>();
    }

    public void addPessoa(PessoaIMC pessoa) {
        lista.add(pessoa);
    }

    public PessoaIMC getPessoa(int index) {
        return lista.get(index);
    }

    public String toStringAll() {
        String str = "";
        for (PessoaIMC pessoa : lista) {
            str += pessoa.toString() + "\n";
        }
        return str;
    }

    public List<PessoaIMC> ordena(int comparador) {
        switch (comparador) {
            case 1:
                Collections.sort(lista, pesoComparator);
                break;

            case 2:
                Collections.sort(lista, alturaComparator);
                break;

            case 3:
                Collections.sort(lista, imcComparator);
                break;

            case 4:
                Collections.sort(lista, nomeComparator);
                break;

            case 5:
                Collections.sort(lista,nomeComparator.reversed());

            case 6:
                Collections.sort(lista, generoComparator);
                break;

            default:
                break;
        }
        return lista;
    }

        
    

    public Comparator<PessoaIMC> pesoComparator = new Comparator<PessoaIMC>() {
        public int compare(PessoaIMC p1, PessoaIMC p2) {
            return (int) (p1.getPeso() - p2.getPeso());
        }
    };

    public Comparator<PessoaIMC> alturaComparator = new Comparator<PessoaIMC>() {
        public int compare(PessoaIMC p1, PessoaIMC p2) {
            return Double.compare(p1.getAltura(), p2.getAltura());
        }
    };

    public Comparator<PessoaIMC> imcComparator = new Comparator<PessoaIMC>() {
        public int compare(PessoaIMC p1, PessoaIMC p2) {
            return (int) (p1.calculaIMC() - p2.calculaIMC());
        }
    };

    public Comparator<PessoaIMC> nomeComparator = new Comparator<PessoaIMC>() {
        public int compare(PessoaIMC p1, PessoaIMC p2) {
            return p1.getNome().compareTo(p2.getNome());
        }
    };

    public Comparator<PessoaIMC> generoComparator = new Comparator<PessoaIMC>() {
        public int compare(PessoaIMC p1, PessoaIMC p2) {
            if (p1 instanceof Homem && p2 instanceof Mulher) {
                return -1;
            } else if (p1 instanceof Mulher && p2 instanceof Homem) {
                return 1;
            } else {
                return 0;
            }
        }
    };

}