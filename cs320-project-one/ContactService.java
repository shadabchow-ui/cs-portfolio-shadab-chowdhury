import java.util.*;

public class ContactService {
    private final Map<String, Contact> contacts = new HashMap<>();

    public void addContact(Contact contact) {
        if (contact == null) throw new IllegalArgumentException("contact cannot be null");
        if (contacts.containsKey(contact.getContactId())) {
            throw new IllegalArgumentException("duplicate contactId");
        }
        contacts.put(contact.getContactId(), contact);
    }

    public void deleteContact(String contactId) {
        contacts.remove(contactId);
    }

    public void updateFirstName(String contactId, String firstName) {
        Contact c = require(contactId);
        c.setFirstName(firstName);
    }

    public void updateLastName(String contactId, String lastName) {
        Contact c = require(contactId);
        c.setLastName(lastName);
    }

    public void updatePhone(String contactId, String phone) {
        Contact c = require(contactId);
        c.setPhone(phone);
    }

    public void updateAddress(String contactId, String address) {
        Contact c = require(contactId);
        c.setAddress(address);
    }

    public Contact get(String contactId) { return contacts.get(contactId); }

    private Contact require(String id) {
        Contact c = contacts.get(id);
        if (c == null) throw new NoSuchElementException("contact not found: " + id);
        return c;
    }
}
