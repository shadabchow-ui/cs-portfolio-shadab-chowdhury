import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import java.util.NoSuchElementException;

public class ContactServiceTest {
    @Test
    void addDeleteUpdate_contactLifecycle() {
        ContactService svc = new ContactService();
        Contact c = new Contact("ID1", "John", "Doe", "1234567890", "Addr");
        svc.addContact(c);
        assertEquals("John", svc.get("ID1").getFirstName());

        // update
        svc.updateFirstName("ID1", "Jane");
        svc.updateLastName("ID1", "Roe");
        svc.updatePhone("ID1", "0987654321");
        svc.updateAddress("ID1", "456 Ave");
        Contact updated = svc.get("ID1");
        assertEquals("Jane", updated.getFirstName());
        assertEquals("Roe", updated.getLastName());
        assertEquals("0987654321", updated.getPhone());
        assertEquals("456 Ave", updated.getAddress());

        // delete
        svc.deleteContact("ID1");
        assertNull(svc.get("ID1"));
    }

    @Test
    void add_duplicateId_throws() {
        ContactService svc = new ContactService();
        svc.addContact(new Contact("ID1", "A", "B", "1234567890", "Addr"));
        assertThrows(IllegalArgumentException.class,
            () -> svc.addContact(new Contact("ID1", "C", "D", "1234567890", "Addr")));
    }

    @Test
    void update_nonexistent_throws() {
        ContactService svc = new ContactService();
        assertThrows(NoSuchElementException.class, () -> svc.updateFirstName("Z", "X"));
    }
}
