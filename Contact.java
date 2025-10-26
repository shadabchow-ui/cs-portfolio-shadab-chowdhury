import java.util.Objects;

public class Contact {
    private final String contactId;
    private String firstName;
    private String lastName;
    private String phone;
    private String address;

    public Contact(String contactId, String firstName, String lastName, String phone, String address) {
        validateId(contactId);
        this.contactId = contactId;
        setFirstName(firstName);
        setLastName(lastName);
        setPhone(phone);
        setAddress(address);
    }

    private void validateId(String id) {
        if (id == null || id.length() > 10) {
            throw new IllegalArgumentException("contactId must be non-null and <= 10 chars");
        }
    }

    private void requireNonNullMax(String val, int max, String field) {
        if (val == null) throw new IllegalArgumentException(field + " cannot be null");
        if (val.length() > max) throw new IllegalArgumentException(field + " too long");
    }

    public String getContactId() { return contactId; }
    public String getFirstName() { return firstName; }
    public String getLastName()  { return lastName; }
    public String getPhone()     { return phone; }
    public String getAddress()   { return address; }

    public void setFirstName(String firstName) {
        requireNonNullMax(firstName, 10, "firstName");
        this.firstName = firstName;
    }
    public void setLastName(String lastName) {
        requireNonNullMax(lastName, 10, "lastName");
        this.lastName = lastName;
    }
    public void setPhone(String phone) {
        if (phone == null) throw new IllegalArgumentException("phone cannot be null");
        if (!phone.matches("\\d{10}")) throw new IllegalArgumentException("phone must be exactly 10 digits");
        this.phone = phone;
    }
    public void setAddress(String address) {
        requireNonNullMax(address, 30, "address");
        this.address = address;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Contact)) return false;
        Contact c = (Contact) o;
        return contactId.equals(c.contactId);
    }

    @Override
    public int hashCode() { return Objects.hash(contactId); }
}
