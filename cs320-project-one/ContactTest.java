import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class ContactTest {
    @Test
    void validContact_isCreated() {
        Contact c = new Contact("ID123", "John", "Doe", "1234567890", "123 Main St");
        assertEquals("ID123", c.getContactId());
        assertEquals("John", c.getFirstName());
        assertEquals("Doe", c.getLastName());
        assertEquals("1234567890", c.getPhone());
        assertEquals("123 Main St", c.getAddress());
    }

    @Test
    void invalidId_throws() {
        assertThrows(IllegalArgumentException.class, () -> new Contact(null, "A", "B", "1234567890", "Addr"));
        assertThrows(IllegalArgumentException.class, () -> new Contact("THIS_IS_LONGER_THAN_10", "A", "B", "1234567890", "Addr"));
    }

    @Test
    void setters_enforceConstraints() {
        Contact c = new Contact("ID1", "John", "Doe", "1234567890", "Addr");
        assertThrows(IllegalArgumentException.class, () -> c.setFirstName(null));
        assertThrows(IllegalArgumentException.class, () -> c.setFirstName("Toolongfirstname"));
        assertThrows(IllegalArgumentException.class, () -> c.setLastName(null));
        assertThrows(IllegalArgumentException.class, () -> c.setLastName("Toolonglastname"));
        assertThrows(IllegalArgumentException.class, () -> c.setPhone(null));
        assertThrows(IllegalArgumentException.class, () -> c.setPhone("12345"));
        assertThrows(IllegalArgumentException.class, () -> c.setAddress(null));
        assertThrows(IllegalArgumentException.class, () -> c.setAddress("x".repeat(31)));
    }
}
