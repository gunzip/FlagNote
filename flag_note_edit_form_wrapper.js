jQuery(document).ready(function () {
    jQuery(".flag_note_js_edit_form_button").css({"cursor":"pointer", "color":"#0071B3"});
    jQuery(".flag_note_js_edit_form_button").click(function(){
      jQuery(this).next(".flag_note_js_edit_form").toggle("slow");
    });

   /* jQuery(".flag_note_js_edit_form .form-submit").click(function(){
      jQuery(this).closest(".flag_note_js_edit_form").toggle("slow");
    });*/
    
    jQuery(".flag").css({"cursor":"pointer", "color":"#0071B3"});
    jQuery(".flag").click(function(){
      jQuery(this).next(".flag_note_js_form").toggle("slow");
    });
});