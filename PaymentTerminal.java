public class PaymentTerminal {
    private double money;  // amount of cash
    private int affordableMeals; // number of sold affordable meals
    private int heartyMeals;  // number of sold hearty meals

    public PaymentTerminal() {
        this.money = 1000;
    }

    public double process(double payment, double price){
        if(payment >= price){
            this.money += payment;
            return payment - price;
        }
        return payment;
    }

    public double eatAffordably(double payment) {
        ++affordableMeals;
        return process(payment, 2.50);
    }

    public double eatHeartily(double payment) {
        ++heartyMeals;
        return process(payment, 4.30);
    }

    public boolean processCard(PaymentCard card, double price){
        if(card.balance() >= price){
            card.addMoney(-price);
            return true;
        }
        return false;
    }

    public boolean eatAffordably(PaymentCard card) {
        if(processCard(card,2.50)){
            ++affordableMeals;
            return true;
        }
        return false;
    }

    public boolean eatHeartily(PaymentCard card) {
        if(processCard(card,4.30)){
            ++heartyMeals;
            return true;
        }
        return false;
    }

    public String toString() {
        return "money: " + money + ", number of sold afforable meals: " + affordableMeals + ", number of sold hearty meals: " + heartyMeals;
    }
}